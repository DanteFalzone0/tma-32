class I32:
  def __init__(self, value: int):
    if value > 2147483647:
      self.value = -2147483648 + (value - 2147483648)
    elif value < -2147483648:
      self.value = 2147483647 + (value + 2147483647)
    else:
      self.value = value

print(str(I32(2147483649).value)) # should print -2147483646
print(str(I32(-2147483650).value)) # should print 2147483645
