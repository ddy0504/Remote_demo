#实例方法
p "10,20,30,40".split(",")
p [1,2,3,4].index(2)
p 1000.to_s
p Time.now.to_s
#类方法--接收者不是对象，而是类本身时的方法
Array.new #创建新的数组,或者Array::new
sleep(1)
def func(a,b = 1,c = 2)
  pass
end
def foo(*args)
  args
end
p foo(1,2,3)

def meth(arg,*args)
  [arg,args]
end
p meth(1)
p meth(1,2,3)

def a(a,*b,c)
  [a,b,c]
end
p a(1,2,3,4,5)
p a(1,2)
#关键字参数
def area2(x:0,y:0,z:0)
  x*z
end
p area2(x:2,y:1)
args1 = {x:3,y:2}
p area2(args1)

def meth(x:0,y:0,z:0,**args)
  [x,y,z,args]
end
p meth(z:1,x:2,y:3,v:4,k:5)
#关键字参数与普通参数搭配使用，首先指定普通参数
def funs(a,b:1,c:1)
  [a,b,c]
end
p funs(2,b:2,c:3)

#将数组分解为参数
def foo(a,b,c)
  a+b+c
end
args1 = [2,3]
p foo(1,*args1)

#用{~}表示散列的字面量，将散列的字面量作为参数传递给方法时可以省略{}
def foo(arg)
  arg
end
p foo({"a"=>1,"b"=>2})
p foo("a"=>1,"b"=>2)
p foo(a:1,b:2)

#有多个参数，只将散列作为最后一个参数传递给方法时
def bar(arg1,arg2)
  [arg1,arg2]
end
p bar(100,{"a"=>1,"b"=>2})
p bar(100,"a"=>1,"b"=>2)
p bar(100,a:1,b:2)

#换行可作为语句结束的标志
str = "hello";print str