with open('include/unicode_char.h', 'a') as writer:
    with open('unicode_char.h', 'r') as reader:
        writer.write(reader.read() + '\n')
