import re
test_string="Modi, is Indian PM @# from BJP.!!!"
print("test_string="+test_string)
words=re.findall(r'\w+', test_string)
print("words="+str(words))
count=len(words)
print("Count of words ="+str(count))