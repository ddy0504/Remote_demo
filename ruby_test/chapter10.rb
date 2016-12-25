#下标方法
class Point

  def [](index)
    case index
      when 0
        x
      when 1
        y
      else
        raise ArgumentError,"out of raneg ~#{index}"
    end
  end

  def []=(index,val)
    case index
      when 0
        self.x = val
      when 1
        self.y = val
      else
        raise ArgumentError,"out of raneg ~#{index}"
    end
  end
end
point1 = Point.new(3,6)
