a,b,*c = 1,2,3,4,5
p [a,b,c]
a,*b,c = 1,2,3,4,5
p [a,b,c]
#置换变量
a,b = 0,1
a,b = b,a
p [a,b]
#获取数组元素
ary = [1,2]
a,b = ary
p a
p b
#获取嵌套数组的元素
ary = [1,[2,3],4]
a,b,c = ary
p a
p b
p c
a,(b1,b2),c = ary
p b1
p b2
p "".empty?
unless 1>2 then
  print ("测试unless\n")
end

tags = ["A","IMG","PRE"]
tags.each do |tagname|
  case tagname
    when "P","A","I","B"
      puts "#{tagname} has child"
    when "IMG","BR"
      puts "#{tagname} has no child"
    else
      puts "#{tagname} cannot be used"
  end
end

array = ["a",1,nil]
array.each do |item|
  case item
    when String
      puts "item is a String"
    when Numeric
      puts "item is a Numeric"
    else
      puts "item is a something"
  end
end

#空行的正则表达式/^$/

p (/zz/ === "xyzzy")
p (String === "xyzzy")
p ((1..3) === 2)
puts "2 比 1大" if 2 > 1
ary1 = []
ary2 = []
p ary1.object_id
p ary2.__id__
#equal?判断是否是同一个对象(ID是否相同)
str1 = "foo"
str2 = str1
str3 = "f" + "o" + "o"
p str1.equal?(str2)
p str1.equal?(str3)
p str1 == str3
p 1.0 == 1
#eql?与==大部分情况执行结果一样，但数值类会重新定义eql?方法
p 1.0.eql?(1)
hash = { 0 => "0"}
p hash[0.0]
p hash[0]



