if __name__ == '__main__':

    # symb = input("Enter the fixed length codewords here(without space):")
    # lenword = int(input("Enter the length of 1 codeword : "))
    symb= '00010000001000110101011110101100'
    lenword = 4
    codeword = []
    for i in range(0,int(len(symb)/lenword)): codeword.append(symb[i*4:(i*4)+4])
    content = [i[-1] for i in codeword]
    position = [bin(i)[2:].zfill(len(codeword).bit_length()-1) for i in range(1, len(codeword))]
    for i in range(len(codeword)): 
        if(int(codeword[i][:-1],2)>0): content[i] = content[int(codeword[i][:-1],2)-1]+content[i]
    position.append("---")
    print('***************************** Lemp-ziv Decoding ***********************')
    print("\t Position \t\t CodeWord \t\t Content")
    for i in range(len(codeword)): print(f"\t {position[i]} \t\t\t {codeword[i]} \t\t\t {content[i]}")
    print('\n***********************************************************************')
    print(f'\n Contents : {content}')
    temp = ''.join(content)
    print(f'\n Contents : {temp} \n')
    print('***********************************************************************')