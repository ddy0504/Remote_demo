
def simple_grep(pattern,filename)
  file = File.open(filename)
  file.each_line do |line|
    if pattern =~ line
      print line.encode(Encoding.find("UTF-8"),Encoding.find("GBK"))+"\n"
    end
  end
  file.close
  test_local
end

def test_local
  $x = 1#全局变量赋值
  x = 1#局部变量赋值
end