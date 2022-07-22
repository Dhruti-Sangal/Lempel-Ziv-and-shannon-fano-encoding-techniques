if __name__ == '__main__':
    # symb = input("Enter the content here: ")
    symb= '101011011010101010'
    content = []
    temp = ''
    for i in symb:
        temp += str(i)
        if temp in content : pass
        else: 
            content.append(temp) 
            temp = ''
     
    codeword = [i[-1] for i in content]
    position = [bin(i)[2:].zfill(len(content).bit_length()-1) for i in range(1, len(content))]
    for i in range(len(content)):
        if len(content[i])>1: codeword[i] = position[content.index(content[i][:-1])] + codeword[i]
        else: codeword[i] = codeword[i].zfill(len(content).bit_length())

    position.append("---")
    print('***************************** Lempel-Ziv Encoding ***********************')
    print("\t Position \t\t Content \t\t Codeword")
    for i in range(len(content)): print(f"\t {position[i]} \t\t\t {content[i]} \t\t\t {codeword[i]} ")
    print('\n***********************************************************************')
    print(f'\n Codewords : {codeword}')
    temp = ''.join(codeword)
    print(f'\n Codewords : {temp} \n')
    print('***********************************************************************')