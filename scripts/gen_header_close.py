with open("include/unicode_data.h", "a") as writer:
    writer.write("}  // namespace unicode\n")
    writer.write("\n#endif  // INCLUDE_UNICODE_DATA_H_\n")

with open("include/unicode_char.h", "a") as writer:
    writer.write("}  // namespace unicode\n")
    writer.write("\n#endif  // INCLUDE_UNICODE_CHAR_H_\n")
