class Set:
    def __init__(self):
        self._s = []
        n = int(input("Enter number of elements: "))
        for _ in range(n):
            x = int(input("Enter Value: "))
            self.add(x)
    
    def getset(self):
        return self._s
    
    def __contains__(self, i):
        return i in self.getset()
    
    def add(self, i):
        if i not in self.getset():
            self.getset().append(i)
        
    def __str__(self):
        return str(self.getset())
        
    def __len__(self):
        return len(self.getset())
    
    def remove(self, i):
        if i in self:
            self.getset().remove(i)
        else:
            print("Element Not in the set")
        
    def __eq__(self, setB):
        if len(self) != len(setB):
            return False
        return self.is_subset(setB)
    
    def is_subset(self, setB):
        for e in setB.getset():
            if e not in self.getset():
                return False
        else:
            return True
        
    def proper_subset(self, setB):
        if self.is_subset(setB) and not setB.is_subset(self):
            return True
        return False
    
    def union(self, setB):
        ans = [e for e in self.getset()]
        for e in setB.getset():
            if e not in ans:
                ans.append(e)
                
        print(ans)
        return
    
    def difference(self, setB):
        print(f"difference of {self.getset()} - {setB.getset()}")
        ans = []
        for e in self.getset():
            if e not in setB.getset():
                ans.append(e)
                
        print(ans)
        
    def intersection(self, setB):
        ans = []
        for e in self.getset():
            if e in setB.getset():
                ans.append(e)
        
        print("Intersection is: ")
        print(ans)