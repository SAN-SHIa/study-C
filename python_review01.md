## python_review

### 细节知识点

#### 命名与保留字

>标识符可以包含**字母（大小写敏感）**、数字和**下划线**，**但不能以数字开头**。
>
>示例：my_variable, count, MAX_SIZE, **_private_var**

#### 运算

```python
a=13//2
#输出a,结果为6，最终结果为去除余数

a=3/4
#输出结果为浮点型，结果为0.75
```

#### and/ or/ not优先级

优先级not—>and—>or

#### 字符串切片

```python
s="love"
print(s[1:3])
#ov

s="love"
print(s[1:-1])
#ov
左闭右开

#字符串不可以通过下标访问但不可通过下标修改元素
s="abcdef"
可以：print(s[0])
不可以：s[0]=1
```

#### 带入数据&保留小数

```python
a=3.14
b=9.123456789
print("{:.1f}".format(a))
#3.1保留一位小数
print(f"{a}+{b}")
#3.14+9.123456789
print(round(b,2))
#9.12保留两位小数
```



---

### 格式

#### 输入格式在同一列

```python
s = input().split()
s = [int(i) for i in s]
调用用s[0]
```

```python
while True:
a,b=map(int,input().split())
print(a+b)
```

#### 向左向右对齐

```python
s="abc"
print("{:>5}".format(s))
print("{:<5}".format(s))
print("{:^5}".format(s))
```

#### 引入模块的方法

```python
from math import factorial
print(factorial(3))
import math
print(math.factorial(3))
import math as m
print(m.factorial(3))
from math import factorial as f
print(f(3))
```

as用于命名库的代称

#### for-else关键字

不遇到break，而正常实现else中的内容

举例：判断质数

#### try-except关键字

```python
try:
    dividend = 10
    divisor = 0
    result = dividend / divisor
    print("Result:", result)
except ZeroDivisionError:
    print("Error: Division by zero!")

try :
    s = "abcdef"
    print(s[0])
except TypeError:
    print("不可以用下标修改字符串中字符的值")
else:
    print("这句话只在没有任何问题时候执行")
```



---



### 组合数据类型

#### 列表

```python
list1=["hhh","kllll"]
#list.append()
list1.append("hehe")
#list.remove()
list1.remove("hehe")
print(list1)
#list.count("item")
data_list = ['python', 'java', 'python', 'php']
print(data_list.count("python"))
#list.pop()
ls=[1,2,3,4,5,6]
print(ls.pop())#6
#list.index(item)
print(ls.index(2))#返回item第一次出现的下标
#list.extend(list2)
ls=[1,3,4,5,6,2,2]
ls2=[5,8,9,6]
ls.extend(ls2)
print(ls)
在list列表尾部加入list2的完整列表
#len(list)
print(len(list1))
list1[0]
#max(list)
price=[779,886,200]
max_price=max(price)
#sorted(list)
sorted_price=sorted(price)
```

**输入一串列表**

```python
s=input().split()
输入的内容用空格分开
#1 2 3 65 45
#['1', '2', '3', '65', '45']
```

#### 字典

**字典类型**

key：value

type（key）的类型根据value来定。

```python
dic={'key':"hello",'num':123456,'float':3.14}
print(type(dic['key']))
print(type(dic['num']))
print(type(dic['float']))
# <class 'str'>
# <class 'int'>
# <class 'float'>
```

**自动识别为列表/字典**

```python
dic=eval(input())
```

**列表或元组转变为字典元素**

```python
以下是一些示例，展示如何使用 dict() 函数将不同类型的可迭代对象转换为字典：
元组：
python
t = (("a", 1), ("b", 2), ("c", 3))
d = dict(t)
print(d)  # 输出: {'a': 1, 'b': 2, 'c': 3}
列表：
lst = [("x", 1), ("y", 2), ("z", 3)]
d = dict(lst)
print(d)  # 输出: {'x': 1, 'y': 2, 'z': 3}
```

**常用方法和函数**

```python
dict={"a":"1","b"="2","c"="3"}

#dict.get(key)
print(dict.get("a"))#1
print(dict.get("d"))#None

#dict.update(dict2)
在更新过程中，两个字典有相同的键，那么会用dict2中的值覆盖原字典中的值。
dict1 = {'a': 1, 'b': 2}
dict2 = {'b': 3, 'c': 4}
dict1.update(dict2)
print(dict1)  # 输出：{'a': 1, 'b': 3, 'c': 4}

#dict.keys()/values()/items()
print(dict.keys())#dict_keys(['a', 'b', 'c'])
print(dict.values())#dict_values(['1', '2', '3'])
print(dict.items())#dict_items([('a', '1'), ('b', '2'), ('c', '3')])
去除其余元素：
    # 遍历得到所有键名
    for key in dict.keys():
        print(key, end=',')
    print()
    # 遍历得到所有的键对应的值
    for value in dict.values():
        print(value, end=',')
    print()
    # 遍历得到所有的键和值
    for k, v in dict.items():
        print(f"key={k} value={v}")
        
#zip(dict1,dict2)
keys=['a','b','c']
values=[1,2,3]
list=list(zip(keys,values))
print(list)# [('a', 1), ('b', 2), ('c', 3)]
diction=dict(zip(keys,values))
print(diction)  #{'a': 1, 'b': 2, 'c': 3}
zip()函数用于将可迭 代的对象作为参数,将对象中对应的元素 打包成一个个元组， 然后返回由这些元组组成的列表。
```

**按某个值排序**

```python
dic1 = {'Tom':21,'Bob':18,'Jack':23,'Ana':20}
dic2 = {'李雷':21,'韩梅梅':18,'小明':23,'小红':20}

dict1 = dict(sorted(dic1.items(), key=lambda x: x[0]))  # 按键的大小升序排序或者见下一行
print((sorted(dic1.keys())[:n])  # 按键的大小升序排序,保留键与值的原本格式，加[xx]输出
dict2 = dict(sorted(dic2.items(), key=lambda x: x[1]))  # 按值的大小升序排序
```

```python
#输出dict1的前n个键的内容
print(list(dict1.keys())[:n])
#输出dict2前n个键值对
print(list(dict2.items())[:n])
sorted（dic.items(),key=lambda x:x[1])
```

#### 集合

```python
# set
s = {1, 2, 3, 4, 5}
s2 = {3, 4, 5, 6, 7}
# & 交集运算
result = s & s2
print(result)  # {3, 4, 5}
# | 并集运算
result = s | s2
print(result)  # {1,2,3,4,5,6,7}
# - 差集
result = s - s2
print(result)   # {1, 2}
# ^ 异或集 获取只在一个集合中出现的元素
result = s ^ s2
print(result)  # {1, 2, 6, 7}
```

---



### 常用函数

#### range()

```python
range（5）
0，1，2，3，4
range（1，5）
含头不含尾
1，2，3，4
range(6,-1,-1)
6,5,4,3,2,1,0
```

#### random()

生成随机数

random.randint(1,10)

生成1-10之间的所有整数，可以输出头和尾

```python
#random库
生成随机设定范围内的随机数
import random
print(random.randint(1,10))

从给定列表元素中随机
from random import choice
ls=[1,5,6,8,4]
print(choice(ls))
```

#### len()

```python
s="helloworld!"
print(len(s))
```

空格和符号也占据长度最终为11

#### str.join（）

```python
list1 = ['g','e','e','k', 's']  
print("".join(list1)) 
```

#### str.strip()

去除空格

#### reversed函数

`reversed()` 函数返回一个反向迭代器对象，它不能直接进行打印输出。为了获取反转后的列表，你可以使用 `list()` 函数将迭代器转换为列表。以下是更新后的代码：

```python
ls=[1,2,5,3]
print(list(reversed(ls)))
```

#### chr&ord函数使用

```python
string = 'azAZ'
for char in string:
    unicode_value = ord(char)
    print(unicode_value)
#输出结果：
97
122
65
90
```

```py
list=[91,92,93,94,95,96,97]
for char in list:
    unicode_value = chr(char)
    print(unicode_value)
#输出结果：
[
\
]
^
_
`
a
```

#### lambda函数

```python
lambda
f = lambda x, y, z: x+y+z
print(f(1, 2, 3))
```

---



### 常用结构

#### 斐波那契数列

```python
#斐波那契数列：
def fib(n):
    if n ==0 or n==1:
        return 1
    else:
        return fib(n-1)+fib(n-2)
n=eval(input())#第n位斐波那契数字
op=fib(n-1)#转化为下标
print(op)
#输出：1 1 2 3 5 8 13
```

#### 阶乘

```python
#迭代函数
def fac(n):
    if n ==0 or n==1:
        return 1
    else:
        return n*fac(n-1)
n=eval(input())#第n位数字
op=fac(n)
print(op)
#math库
from math import factorial
print(factorial(3))
```

#### 判断打印质数

```python
n=eval(input())
for i in range(2,n+1):
    for j in range(2,i):
        if i%j==0:
            break
    else:
        print(i,end=" ")

```

#### 乘法口诀表

```python
#方法一
for i in range(1,10):
    for j in range(1,i+1):
        print("%d*%d=%d"%(i,j,i*j),end=' ')
    print()
#方法二
i=1
while(i<=9):
    j=1
    while(j<=i):
        print("%d*%d=%d"%(i,j,i*j),end=" ")
        j+=1
    print()
    i+=1
```

#### 统计一段字符串/列表中各个元素的数量

```python
str="I love you three thousand times!"
dict={}
for i in str:
    dict[i]=dict.get(i,0)+1
print(dict)
```

#### 分割输入信息并存入列表

```python
n=int(input())
ls=[]
while True:
    line=input().split(" ")
    if line==["end"]:
        break
    else:
        ls.append(line)
```

---



### 文件

#### 文件绝对路径，相对路径

```py
file = open('E:\\桌面\\hhh.txt', 'r', encoding='utf-8')
file = open('hhh.txt', 'r', encoding='utf-8')
content = file.read()
print(content)
file.close()
```
