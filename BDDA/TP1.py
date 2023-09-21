personnes = []
def ADD(nom):
    personnes.append(nom)

def LIST(liste):
    for e in liste:
        print(e, end=", ")
    print("")

def menu():
    quit = False
    while not quit :
        saisie = input("saisissez une operation : ") 
        if(saisie == "Q"):
            quit = True
        else : 
            operation = (saisie.split())
            if(operation[0]== "ADD"):
                ADD(operation[1])
                
            if(operation[0]== "LIST"):
                quit = True
                LIST(personnes)
                      
menu()