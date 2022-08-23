print("hello")

num = 40
str = "aaaaa"
t = nil

while num < 40 do
    num = num + 1
end

if num > 40 then
    print("40!")
end

print(t, ttttttt)

t = true and "yes" or "no"

print(t)

t = 0
for i = 1, 100 do
    t = t + i
end

print(t)

-------------------------------------------

function fib(n)
    return n <= 2 and 1 or fib(n - 1) + fib(n - 2)
end

for i = 1, 10 do
    print(fib(i))
end

t = { k1 = "123", k2 = false, ["***"] = "###" }
print(t)
print(t.k1)
print(t["***"])
function printObj(o)
    print(o)
    for x, v in pairs(o) do
        print(x, "==", v)
    end
end
printObj(t)

function h(x)
    print(x.key1)
end
h { key1 = 'Sonmi~451' }

printObj(_G)

v = { 'value1', 'value2', 1.21, 'gigawatts' }
for i = 1, #v do
    print(v[i])  -- Indices start at 1 !! SO CRAZY!
end