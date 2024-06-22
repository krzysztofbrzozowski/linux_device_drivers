f = open('/dev/scull0', 'w')
print(f.write('TEST'))
f.close()

f = open('/dev/scull0', 'r')
print(f.read())
f.close()