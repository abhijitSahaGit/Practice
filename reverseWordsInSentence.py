def reverseWordSentence(sentence): 
	# Spliting into words. 
	words = sentence.split(" ") 
	print("words="+str(words))

	newWords = [word[::-1] for word in words] 
	print("newWords="+str(newWords))
	
	newSentence = " ".join(newWords) 
	return newSentence 

# Driver's Code 
sentence = "Abhijit is a good boy"
print(reverseWordSentence(sentence)) 