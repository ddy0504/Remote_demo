puts "首个参数： #{ARGV[0]}"
puts "首个参数： #{ARGV[1]}"
puts "首个参数： #{ARGV[2]}"

# puts "What is your name?"
# $name = STDIN.gets
# puts "Hi "+$name

file = File.open("111.txt")
test = file.read
test = test.encode(Encoding.find("UTF-8"),Encoding.find("GBK"))
puts test
file.close

pattern = Regexp.new("aaa")#创建正则对象
file = File.open("111.txt")
file.each_line do |line|
  if pattern =~ line
      puts line.encode(Encoding.find("UTF-8"),Encoding.find("GBK"))
  end
end
file.close

require 'date'
days = Date.today - Date.new(1988,5,4)
puts (days.to_i)

require 'pp'
v = [{
     key00: "《武林秘籍》",
     key01: "《九阴真经》",
     key02: "《一阳指》"
     }]
p v
pp v