#查看对象属于哪个类
ary = []
str = "hello"
p ary.class
p str.class
p ary.instance_of?(Array)
p str.instance_of?(String)
p str.is_a?(String)
p str.is_a?(Object)

class HelloWorld
  def initialize(myname = "Ruby")
    @name = myname  #初始化实例变量,以@开头的变量为实例变量
  end

  def hello
    puts "Hello,I am #{@name}"
  end

  #对象外部不能直接访问实例变量,需要用方法
  attr_reader :name #设置name为只读属性，相当于下面方法
  # def name
  #   @name
  # end

  attr_writer :name #设置只写属性
  attr_accessor :name #读写
  # def name=(value)
  #   @name = value
  # end
end

bob = HelloWorld.new("Bob")
bob.hello
p bob.name
ruby = HelloWorld.new
ruby.hello

#方法的接收者就是类本身（类对象）的方法称为类方法
class << HelloWorld
  def hello(name)
    puts "#{name} said hello"
  end
end
HelloWorld.hello("Hohn")

class Hello
  Version = "1.0"
end
p Hello::Version

#类变量，以@@开头，所有实例共享
class HelloCount
  @@count = 0 #调用hello方法的次数

  def HelloCount.count #读取调用次数的类方法
    @@count
  end

  def initialize(myname = "Ruby")
    @name = myname  #初始化实例变量,以@开头的变量为实例变量
  end

  def hello
    @@count += 1
    puts "Hello I am #{@name}\n"
  end
end
bob = HelloCount.new("Bob")
alice = HelloCount.new("Alice")
ruby = HelloCount.new
p HelloCount.count
bob.hello
alice.hello
ruby.hello
p HelloCount.count

#限制方法的调用
class AccTest
  def pub
    puts "pub is a public method"
  end

  public :pub #把pub方法设定为public，不加:pub时，以下方法都是public

  def priv
    puts "priv is a private method"
  end

  private :priv
end
acc = AccTest.new
acc.pub
#acc.priv #不能正常使用

class Point
  attr_accessor :x,:y
  protected :x=,:y=

  def initialize(x = 0.0,y = 0.0)
    @x,@y = x,y
  end

  def swap(other)
    tmp_x,tmp_y = @x,@y
    @x,@y = other.x,other.y
    other.x,other.y = tmp_x,tmp_y

    return self
  end
end

p0 = Point.new
p1 = Point.new(1.0,2.0)
p [p0.x,p0.y]
p [p1.x,p1.y]
p0.swap(p1)
p [p0.x,p0.y]
p [p1.x,p1.y]
#p0.x = 10.0 #不能对protected变量赋值，否则后续再也输出不了

#扩展类
class String
  def count_word
    ary = self.split(/\s+/)#用空格分割
    return ary.size
  end
end
str = "Just do it"
p str.count_word

class RingArray < Array #指定父类
  def [](i)             #重定义运算符[]
    idx = i%size        #计算新索引值，指定超过数组长度的索引时，重新计算索引
    super(idx)          #调用父类中同名函数,也就是Array#[]
  end
end
wday = RingArray["日","月","火","水","木","金","土"]
puts wday[6]
puts wday[11]
puts wday[15]
puts wday[-1]

#alias给存在的方法设置别名
class C1
  def hello
    "Hello"
  end
end

class C2 < C1
  alias old_hello hello #给父类的hello设置别名，删除父类方法用undef hello
  def hello
    "#{old_hello},again"
  end
end
obj = C2.new
p obj.old_hello  #会调用父类方法
p obj.hello      #调用子类方法

#通过利用单例类定义，可以给对象添加方法(单例方法)
str1 = "Ruby"
class << str1
  def hello
    "Hello,#{self}!"
  end
end

#创建模块
module HelloModule
  Version = "1.0"

  def hello(name)
    puts "Hello, #{name}"
  end

  module_function :hello  #指定hello方法为模块函数
end

p HelloModule::Version
HelloModule.hello("Alice")

include HelloModule
p Version
hello("Alice")

#Mix-in
module M
  def meth
    "meth"
  end
end

class C
  include M
end

c = C.new
p c.meth

p C.include?(M)
p C.ancestors #返回C类的继承关系
p C.superclass #返回C的父类

#extend批量定义单例方法
module Edition
  def edition(n)
    "#{self} 第#{n} 版"
  end
end

str = "Ruby 基础教程"
str.extend(Edition) #将模块Mix-in进对象
puts str.edition(4)

module ClassMethods #定义类方法的模块
  def cmethod
    "class method"
  end
end

module InstanceMethods #定义实例方法的模块
  def imethod
    "instance method"
  end
end

class MyClass
  #使用extend方法定义类方法
  extend ClassMethods
  #使用include定义实例方法
  include InstanceMethods
end

p MyClass.cmethod
p MyClass.new.imethod

f = 3.14
p f.round  #四舍五入
p f.ceil   #进位

#鸭子类型
def fetch_and_downcase(ary,index)
  if str = ary[index]
    return str.downcase
  end
end
ary = ["Boo","FOo","Woo"]
p fetch_and_downcase(ary,1)
hash = {0=>"Boo",1=>"Foo",2=>"Woo"}
p fetch_and_downcase(hash,1)#传散列

require 'net/http'
require "uri"
url = URI.parse("http://www.ruby-lang.org/ja/")
p url.scheme  #输出"http"  (体系：URL的种类)
p url.host    #输出"www.ruby-lang.org"  （主机名）
p url.port    #输出"80"     (端口号)
p url.path    #输出"/ja/"   (路径)
p url.to_s
http = Net::HTTP.start(url.host,url.port)
doc = http.get(url.path)
puts doc