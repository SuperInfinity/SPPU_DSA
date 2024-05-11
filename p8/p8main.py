from p8 import Set

def menu():
    print("*-----First initialize two sets-----*")
    a = Set()
    b = Set()
    
    while True:
        print("----------------Menu-----------------")
        print("1.Show sets\n2.Search elements\n3.Add more elements\n4.Remove Elements\n5.Union\n6.Difference\n7.Intersection\n8.check for Subset\n9.Exit")
        ch = int(input("Enter choice: "))
        if ch == 1:
            print(str(a))
            print(str(b))
        elif ch == 2:
            n = int(input("Enter element u want to search: "))
            if n in a.getset():
                print("Element in A")
            elif n in b.getset():
                print("Element in B")
            else:
                print("Element not found in Both sets")
        elif ch == 3:
            n = int(input("Enter Value: "))
            print("Value will be added in both sets.!")
            a.add(n)
            b.add(n)
        elif ch == 4:
            n = int(input("Enter element to want to remove: "))
            a.remove(n)
            b.remove(n)
        elif ch == 5:
            a.union(b)
        elif ch == 6:
            a.difference(b)
        elif ch == 7:
            a.intersection(b)
        elif ch == 8:
            if a.is_subset(b):
                print("B is subset of A")
            elif b.is_subset(a):
                print("A is subset of B")
        else:
            break
        
def main():
    menu()
    
if __name__ == '__main__':
    main()