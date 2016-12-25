=begin
第一次练习
=end

print("hello,ruby.\n")
puts "hello,ruby+中文"#puts默认带\n
puts "hello","ruby"
#使用p方法时，引号内特殊字符 不会被转义
p 100
p "100"
p Math.sin(3.1415)
p Math.sqrt(10000)
area = 20*20
print "表面积= #{area}\n"
p ("abc" == "abc")
a=20
if a>20 then
  print("大于\n")
elsif a>10 then
  print("大于10\n")
else
  print("小于\n")
end
i=1
while i<10 do#do可以省略
  print i,"\n"
  i += 1
end
#times方法被称为迭代器
5.times do
  print "中文"
end

names = ["小孩","打人","美女"]
print "第一个名字为:",names[0],"\n"
print "文件大小：",names.size,"\n"
names.each do |n|
  print n
end

#符号
sum = :foo
#符号转换成字符串
print sum.to_s
#字符串转换为符号
print "foo".to_sym

address = {:name=>"高桥",:f1 =>"高山",:f2=>"流水"}
#将符号当作键值来使用
address = {name:"高桥",f1:"高山",f2:"流水"}
print address[:f1]
address.each do |key,value|
  puts "#{key}: #{value}"
end

puts /ruby/ =~ "aruby"
print /ruby/ =~ 'arub'
#加i表示不区分大小写
puts /ruby/i =~ "aRuby"
names.each do |name|
  if/打/=~name
    puts name
  end
end

gets