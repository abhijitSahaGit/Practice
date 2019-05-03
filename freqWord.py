def freqWord(sentence): 
	# Spliting into words. 
	words = sentence.split(" ") 
	print("words="+str(words))

	uniqueWords = set(words)
	for word in uniqueWords:
	    print("Freq of "+str(word)+" ="+str(words.count(word)))


# Driver's Code 
sentence = "apple mango apple orange orange apple guava mango mango"
print(freqWord(sentence))