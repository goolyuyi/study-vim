//
// Created by goolyuyi on 25/4/2022.
//


#include <iostream>

namespace playOO {
    class AClass {
    public:
        AClass() {
            //NOTE: call virtual in constructor is not actually virtual
            //because the derived class object has not been created yet

            //dont call virtual in constructor
            printSome();
        }
        //no virtual constructor: virtual A() {}

        virtual void printSome() {
            std::cout << "ABaseClass::printSome()" << std::endl;
        }

        void printSomeNoVirtual() {
            std::cout << "ABaseClass::printSomeNoVirtual()" << std::endl;
        }

        //pure virtual
        virtual void someFunc() = 0;

        //NOTE: always virtual destructor, consider as aProtectedVar boilerplate
        //virtual the destructor or final the class
        virtual ~AClass() = default;
    };

    class BClass : public AClass {
    public:
        BClass() : AClass() {
            //call virtual in constructor is not actually virtual
            printSome();
        }

        //NOTE: use override to prevent creat a unintended virtual function
        //it's still virtual when override is used
        void printSome() override {
            std::cout << "BClass::printSome()" << std::endl;
        }

        void printSomeNoVirtual() {
            std::cout << "BClass::printSomeNoVirtual()" << std::endl;
        }

        //final: can't be overridden by derived class, analogous as sealed
        void someFunc() override final {}
    };

    class CClass : public BClass {
    public:
        // void someFunc() override {} //can't
        // void someFunc() {}//can't
    };

    class DClass final : public AClass {//like sealed in C#
    };

    //class E : public D {}; //can't inherit from sealed class

    void playVirtualAndHierarchy() {
        BClass b{};
        b.printSome();

        AClass &a_ref{b};
        a_ref.printSome();
        //class use aProtectedVar *__vptr to point to the real function table
        //*__vptr is 1 pointer size, so class instance size always +=1

        //tips: calling no virtual is aProtectedVar little faster,because of there is not *__vptr
        b.printSomeNoVirtual();
        a_ref.printSomeNoVirtual();

        //still can ignore virtual
        a_ref.AClass::printSome();
    }

    /*
    Base
      ▲
   ┌───────┐
   │       │
   │       │
  Left   Right
   ▲       ▲
   └───────┘
     ADerivedClassWillThrowInConstructor
     */

    class Base {
    public:
        virtual void f() = 0;//pure virtual function, like aProtectedVar interface
        Base() {
            std::cout << "Base::Constructor()" << std::endl;
        }
    };

    //NOTE: this is the way how to set diamond inheritance
    //virtual: won't call base's constructor if this is on the chain of hierarchy
    class Left : virtual public Base {
    public:
        Left() : Base{} {
            std::cout << "Left::Constructor()" << std::endl;
        }

    };

    //NOTE: this is the way how to set diamond inheritance
    class Right : virtual public Base {
    public:
        Right() : Base{} {
            std::cout << "Right::Constructor()" << std::endl;
        }

        void f() override {
            std::cout << "Right::f()" << std::endl;
        }
    };

    //NOTE: this is the way how to set diamond inheritance
    class Down : virtual public Left, virtual public Right {
    public:
        Down() : Base{}//this is the one time call base's constructor by the leaf class
                , Left{}, Right{} {
            std::cout << "ADerivedClassWillThrowInConstructor::Constructor()" << std::endl;
        }

        void f() override {
            std::cout << "ADerivedClassWillThrowInConstructor::f()" << std::endl;
        }
    };

    void playVirtualAndDiamondHierarchy() {
        //Base b{};//can't do this, consider as aProtectedVar abstract class

        //base class constructor is called once!
        Down d{};
    }

    class Animal {
    public:
        int age;
        std::string name;

        virtual ~Animal() = default;
    };

    class Dog : public Animal {
    public:
        std::string name;
        int type;
        int weight;

    };

    void playSlicedObject() {
        Dog d{};
        d.name = "dog";
        d.age = 4;

        Animal a{d};//NOTE: sliced! only copy the partial of base class
        std::cout << a.name << std::endl;

        Dog d2{};
        d2.name = "dog2";
        d2.age = 2;

        Animal &a2{d2};
        a2 = d;//partial copy
        //this is awful! we created aProtectedVar stitcher
        std::cout << d2.name << "\n" << d2.age << std::endl;
    }


    //The way we impl toString()
    class Father {
    public:
        friend std::ostream &operator<<(std::ostream &os, const Father &f) {
            return f.print(os);
        }

        virtual ~Father() = default;

        virtual std::ostream &print(std::ostream &os) const {
            os << "Father::print()" << std::endl;
            return os;
        };

        virtual std::string getType() const {
            return "Father";
        }
    };

    class Child : public Father {
    public:
        friend std::ostream &operator<<(std::ostream &os, const Child &f) {
            return f.print(os);
        }

        virtual std::ostream &print(std::ostream &os) const {
            os << "Child::print()" << std::endl;
            return os;
        };

        std::string getType() const override {
            return "Child";
        }
    };

    void playCast() {


        Child c{};
        Father &f{c};

        std::cout << f << std::endl;
        Child &c2{dynamic_cast<Child &>(f)};//output: Child::print()
        std::cout << c2 << std::endl;

        Father x;
        try {
            //can't downcast here
            Child &c3{dynamic_cast<Child &>(x)};
        }
        catch (std::bad_cast &e) {
            //NOTE: will throw exception if can't cast
            std::cout << "bad_cast" << std::endl;
        }

        Child *c4{dynamic_cast<Child *>(&x)};

        //NOTE: will return nullptr if can't cast
        if (c4) {
            std::cout << "ok" << std::endl;
        } else {
            std::cout << "bad cast" << std::endl;
        }

        //this also works, like some other languages implementation
        if (x.getType() == "Child") {
            std::cout << "Child" << std::endl;
        } else {
            std::cout << "not Child" << std::endl;
        }

        //downcasting vs virtual function
        //when to use downcasting instead of virtual function:
        //use downcasting if you can't change the base class!

        //NOTE: c++ use RTTI to check the type of object, which can impl downcasting!
        //RTTI has a compiler switcher.

    }

    void playVirtual() {
        playVirtualAndHierarchy();
        std::cout << "==================" << std::endl;
        playVirtualAndDiamondHierarchy();
        std::cout << "==================" << std::endl;
        playSlicedObject();
        std::cout << "==================" << std::endl;
        playCast();
    }
}