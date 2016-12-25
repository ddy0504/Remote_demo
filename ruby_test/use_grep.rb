require './grep'#调用库用require，库与脚本放在同一目录，用./表示

$x = 0
x = 0

pattern = Regexp.new("aaa")#创建正则对象
filename = "111.txt"
simple_grep(pattern,filename)

p $x
p x