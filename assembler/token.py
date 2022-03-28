from enum import Enum

class TokenType(Enum):
  address_label = 0
  dot_directive = 1 # ".asciz", ".zero"
  hash_directive = 2 # "#include", "#define"
  register = 3 # "ip", "sp", or any of "r{n}" for n >= 0 and < 16
  mnemonic = 4 # any of the instructions we support
  string_literal = 5
  int_literal = 6 # ends with "i" if signed; defaults to unsigned otherwise
  colon = 7
  line_terminator = 8
  syntax_error = 9


class Token:
  def __init__(self, type: TokenType, value: str):
    self.type = type
    self.value = value

  def __repr__(self):
    return f"<Token of type {self.type} with value {self.value}>"

  def __str__(self):
    return self.value
