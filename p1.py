# Globle data..
clients = {} # To store client name and using number as key
hash_table = [] # Our hash table

def hashit(key, n):
    return key % n

def search(hash_table ,key):
    x = key % len(hash_table)
    if hash_table[x] == key:
        print("Found..!")
        print(f"Name is: {clients[key]}")
        return 
    else:
        i = x
        x = (x + 1) % len(hash_table)
        while x != i:
            if hash_table[x] == key:
                print("Found..!")
                print(f"Name is: {clients[key]}")
                return 
            x = (x + 1) % len(hash_table)
            
        print("Not in the table")
        return

def linearProb(hash_table, key):
    index = hashit(key, len(hash_table))
    if hash_table[index] == -1:
        hash_table[index] = key
    else:
        i = index
        index = (index + 1) % len(hash_table)
        while i != index:
            if hash_table[index] == -1:
                hash_table[index] = key
                return
            index = (index + 1) % len(hash_table)
        print("Table Full..!")

def qadraticProb(hash_table, key):
    index = hashit(key, len(hash_table))
    if hash_table[index] == -1:
        hash_table[index] = key
    else:
        i = index
        j = 1
        index = (index + (j ** 2)) % len(hash_table)
        while i != index:
            if hash_table[index] == -1:
                hash_table[index] = key
                return
            if j > len(hash_table):
                print("Table Full..!")
                return
            j += 1
            index = (index + (j ** 2)) % len(hash_table)
        print("Table Full..!")

def main():
    n = int(input("Enter Number of clients at first: "))
    hash_table = [-1 for i in range(n)]
    while True:
        print("----------------Menu----------------")
        print("----------1.Insert Clients----------")
        print("----------2.Search Clients----------")
        print("------------3.End Program-----------")
        ans = int(input("Enter Choice: "))
        if ans == 1:
            while True:
                name = input("Enter the name for the clients: ")
                num = int(input("Enter the numeber of the client: "))
                clients[num] = name
                x = int(input("How would u like to inser the number?\n1.Linear Probing\n2.Qadratic Probing\n--> "))
                
                if x == 1:
                    linearProb(hash_table, num)
                elif x == 2:
                    qadraticProb(hash_table, num)
                    
                k = input("Do u want to add more clients? (Y/n): ")
                
                if not k:
                    pass
                elif k.lower() != 'y':
                    break
                
            print(hash_table)
        
        elif ans == 2:
            key = int(input("Enter number u want to search: "))
            search(hash_table, key)
        
        else:
            break
        
    return 0



main()