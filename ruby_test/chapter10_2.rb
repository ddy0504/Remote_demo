array = ["ruby","Perl","PHP","Ptyhon"]
sorted = array.sort
p sorted
#调用块
sorted = array.sort{|a,b| a <=> b}
p sorted
#用<=>运算符比较数值时，得到由小到大的顺序
sorted = array.sort{|a,b| a.length <=> b.length}
p sorted

ary = %w(Ruby is a open)
call_num = 0
sorted = ary.sort do |a,b|
  call_num += 1
  a.length
end
puts "排序结果 #{sorted}"
puts "数组元素数量 #{ary.length}"
puts "调用块的次数 #{call_num}"
sorted = ary.sort_by{|item| item.length}
puts "排序结果 #{sorted}"
puts "数组元素数量 #{ary.length}"
puts "调用块的次数 #{call_num}"

#定义带块的方法
def myloop
  while true
    yield    #执行块
  end
end

num = 1
myloop do
  puts "num is #{num}"
  break if num > 100
  num *= 2
end

def total(from,to)
  result = 0
  from.upto(to) do |num|      #处理从from到to的值
    if block_given?           #如果有块的话
      result += yield(num)
    else
      result += num
    end
  end
  return result
end
p total(1,10)
p total(1,10){|num| num ** 2}

hash = {a:100,b:200,c:300}
hash.each_with_index do |(key,value),index|
  p [key,value,index]
end

n = total(1,10) do |num|
  if num == 5
    break 0     #在块内break,会返回到调用块的地方，指定break参数作为返回
  end           #next 中断当前处理，继续执行下面的处理
  num
end
p n

#将块封装成对象
hello = Proc.new do |name|  #proc对象能让块作为对象在程序中使用
  puts "Hello ,#{name}"
end
hello.call("world")

def total2(from,to,&block)
  result = 0
  from.upto(to) do |num|
    if block
      result += block.call(num)  #执行块的语句
    else
      result += num
    end
  end
  return result
end
p total2(1,10)
p total2(1,10){|num| num**2}

def call_each(ary,&block)
  ary.each(&block)#将proc对象作为块传给ary.each
end

call_each [1,2,3] do |item|
  p item
end

x = 1
y = 1
ary = [1,2,3]
ary.each do |x| #将x作为块变量使用
  y = x
end
p [x,y]