#Class to create suffix tree using Ukonnen Algorithm

class SuffixNode:
    def __init__(self,suffix_link=None):
        self.children={}
        if suffix_link is not None:
            self.suffix_link=suffix_link
        else:
            self.suffix_link=self
    def add_link(self,c,v):
        self.children[c]=v 


def build_trie(s):
    assert len(s)>0
    Root=SuffixNode()
    Longest=SuffixNode(suffix_link=Root)
    Root.add_link(s[0],Longest)

    for c in s[1:]:
        cur=Longest
        prev=None
        while c not in cur.children:
            r1=SuffixNode()
            cur.add_link(c,r1)
            if prev is not None:
                prev.suffix_link=r1
            prev=r1
            cur=cur.suffix_link
        if cur is Root:
            prev.suffix_link=Root
        else:
            prev.suffix_link=cur.children[c]

        Longest=Longest.children[c]

    return Root
