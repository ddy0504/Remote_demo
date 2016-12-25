7.times do |i|
  puts "第#{i}次循环"
end
sum = 0
from = 1
to = 5
for i in from..to
  sum += i
end
puts sum
sum = 0
until sum>=50
  sum += 1
end
puts sum
sum = 0
(1..5).each do |i|
  sum += i
end
puts sum

i =0
["aa","bb","cc","dd"].each do |lang|
  i+=1
  if i==3
    redo#返回i+=1处重新执行
  end
  p [i,lang]
end

file = File.open("111.txt")
file.each_line do |line|
  next if /^\s*$/ =~ line #空行
  next if /^#/ =~ line #以#开头
  puts line.encode(Encoding.find("UTF-8"),Encoding.find("GBK"))
end
file.close
5.times{|i| puts i}
5.times do |i| puts i end