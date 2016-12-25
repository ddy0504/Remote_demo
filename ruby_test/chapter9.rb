$stdin.lineno += 1
$stdin.lineno = $stdin.lineno + 1
p (5...10).to_a

#range对象内succ方法逐个生成接下来的值
var = "a"
p var.succ

#定义二元运算符
class Point
  attr_reader :x,:y

  def initialize(x=0,y=0)
    @x,@y = x,y
  end

  def inspect
    "(#{x},#{y})"
  end

  def +(other)
    self.class.new(x + other.x,y + other.y)
  end
end

point0 = Point.new(3,6)
point1 = Point.new(1,8)
p point0
p point1
p point0 + point1

#一元运算符
class Point

  def +@
    dup  #返回自己的副本
  end

  def -@
    self.class.new(-x,-y)
  end

  def ~@
    self.class.new(-y,x)
  end
end
point = Point.new(3,6)
p +point
p -point
p ~point


