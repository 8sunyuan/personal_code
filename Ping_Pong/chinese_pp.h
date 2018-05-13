#ifndef __CHINESE_PP_H__
#define __CHINESE_PP_H__


typedef struct BallGroup 
{
    int  totalNum;
    int  level;
    
    bool isTested;
    bool isPartitioned;
    
    BallGroup *parent;
    BallGroup *left;
    BallGroup *mid;
    BallGroup *right;
} BallGroup_t;


typedef struct ListNode
{
    ListNode    *pNext;
    BallGroup_t *pTreeNode;
} ListNode_t;



class ChinesePingPong
{
public:
    
    ChinesePingPong();
    ~ChinesePingPong();
    
    
    void PrintTree(int N);
    int  FindMinTests(int N);
    
protected:
    
    void Init();
    void CleanTree();
    void BuildTree(int N);
    int  PartitionGroup(BallGroup_t *pGroup);
    void PrintPath(BallGroup_t *pGroup);
    
    BallGroup_t* FindOneFromList(ListNode_t* pPool);
    BallGroup_t* AddOneToList(ListNode_t* pPool);
    
    void Push(BallGroup_t* pGroup);
    BallGroup_t* Pop(void);
    
private:
    
    int          m_totalNumBalls;
    int          m_minTestsRequired;
    BallGroup_t  m_PingPongTree;

    ListNode_t   m_NodePool;
    ListNode_t   m_BacktrackStack;
};

#endif