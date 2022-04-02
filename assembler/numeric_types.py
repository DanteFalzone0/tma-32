import ctypes

class I32:
  def __init__(self, value: int):
    if value > 2147483647 or value < -2147483648:
      raise ValueError(f"unable to store value {value} in a 32-bit signed integer")
    else:
      self.value = ctypes.c_int32(value)


class U32:
  def __init__(self, value: int):
    if value > 4294967295 or value < 0:
      raise ValueError(f"unable to store value {value} in a 32-bit unsigned integer")
    else:
      self.value = ctypes.c_uint32(value)


class F32:
  def __init__(self, value: float):
    self.value = ctypes.c_float(value)
