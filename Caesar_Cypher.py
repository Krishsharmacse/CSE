Alphabets=[]
for i in range(65, 123):
    if(i >= 91 and i <= 96):
        continue
    Alphabets.append(chr(i))

def cypher(original_text, shift, encode_decode):
    output_text=""
    if encode_decode == "DECODE":
            shift *= -1
    for letter in original_text:
        shifted_position = Alphabets.index(letter) + shift
        shifted_position %= len(Alphabets)
        output_text += Alphabets[shifted_position]
    print(f"Encoded Text : {output_text}")



Name = input("What is your name?\n")
print(f"\nHello {Name} !! \nWelcome to Caesar Cypher")

Function = input("Type 'ENCODE' to encrypt/'DECODE' to decrypt message :\n").upper()


if Function!= "ENCODE" and Function!="DECODE":
    print("Oops Something went wrong :( \nPlease try again ")

else :
    message= input("Type the message you want to cypher :\n")
    key=int(input("How much SHIFT do you want/encryption key or decryption key? \n "))
    cypher(original_text=message, shift=key, encode_decode=Function)