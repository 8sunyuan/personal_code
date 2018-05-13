/* 
   COPYRIGHT by Author Jianli Sun, 2004 ~ 2015; full rights reserved.
   
   1) The Chinese Ping-Pong Problem:
   --------------------------------

     For a given group of N balls, there is only one bad ball with wrong weight.
     How to find it with minimum number of test if you are given a scale that
     can only tell you two sides are balanced or not.
     
     
   2) The Analysis:
   ----------------
   
    We assume the scale has L-end and R-end; the test condition is that each 
    test MUST put equal number of balls in L-end and R-end; and the scale may 
    have the following three possible states: 
       
           s:             state
           -----------------------------------------
           0:       balanced
           1:       unbalanced with L-end going down
           2:       unbalanced with R-end going down

     This is a binary search problem, except that it is not dividing into two 
     equal sub-groups, but rather into 3 sub-groups: grp1, grp2, grp3. 

     The first test can at most eliminate grp3, or 1/3 of the whole. However,
     each of the succeeding tests can eliminate 2/3 of (grp1 + grp2) that are 
     put on the two sides of the scale. 

    Theorem 1:  For M balls on the scale in a state s, if changing the distribution
                of a subset of M balls does not change the state of the scale, then 
                these subset of balls are good balls; otherwise they are bad balls.
                
    A ball on the scale may have two possible ways to change the distribution; either
    moving to the other side of the scale, or moving to the outside the scale.
                

    Theorem 2:  For M balls on the scale in a state, adding or removing good balls 
                into or from the scale will not change the state of the scale.
                 
    The above theorem is helpful to arrange the tests by adding or removing good
    balls so that both sides of the scale have equal number of balls. That is,
    the testing process is to find more and more good balls, which may result in
    both sides not having equal number of balls. In this case, you can think that
    some "good balls" are virtually added to the empty spots as long as we have 
    found enough good balls from the previous tests.    
    
    
    3) The Method:
    --------------
    
    In the very beginning, the total number of N balls are divided into TWO sub-groups.
    Group A with M = 2/3 N balls that will be put onto the scale to test (half on each 
    side); and Group B with 1/3 balls that will be put outside of the scale.
    
    3.1 The Remainder Handling Algorithm (RHA):
        The key part is how to handle remainders of the partitions:
    
        If remainder = 1, put the remaining ball into the scale if this is 
        NOT the very first test (requires even balls on the scale).
        
        If remainder = 2, then put them in two separate groups: 
            - For two sub-groups of Level 0 partition; put ONLY-1 ball for the  
              group on the scale to test.
            - For three sub-groups of Level > 0 partition; put two balls in any 
              two sub-groups. They are all on the scale to test anyway.

    3.2 The overall Decision-Tree-Traversal Algorithm:
    
        If Group A balls cause the scale balanced, then the bad ball is in Group B; 
        otherwise the M balls on the scale will now be organized into THREE groups 
        for further tests.
        
        Based on Theorem 1, we can obtain the following result:

    Theorem 3:  Dividing the M balls on the scale into 3 sub-groups: grp1, grp2, and grp3.
                After taking grp3 outside the scale, and making grp2 change the siding 
                within the scale, then another test can determine the bad ball in which 
                one of the three sub-groups.

    That is, Theorem 3 tells that a single test for a tested group of M balls (in an 
    unbalanced state) will eliminate 2/3 of M balls, which are good balls. 
    
    Thus, the total number of tests required to find the bad ball:   
    
             T(N) = 1 + log3 (2N / 3)
             
    T(N) = 1    2        3            4             5                6
    -------------------------------------------------------------------------------
           1  2 3 4  5 6 ... 13  14 15 ... 40  41 42 ... 121   122 123  ... 364  ......
              -----  ----------  ------------  --------------  ----------------
        3**0    3      9             27             81              243
    -------------------------------------------------------------------------------      
            
*/

#include "chinese_pp.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

const int debug = 0;
// ---------------------------------------------------------------
// Constructor:  initialize all member variables.
//
ChinesePingPong::ChinesePingPong()
{
    Init();
}

// ---------------------------------------------------------------
//  Destructor
//
ChinesePingPong::~ChinesePingPong()
{
    CleanTree();
}

// ---------------------------------------------------------------
//
//
void ChinesePingPong::Init()
{
    m_totalNumBalls = 0;
    m_minTestsRequired = 0;
    
    m_PingPongTree.totalNum = 0;
    m_PingPongTree.level = 0;
    m_PingPongTree.isTested = false;
    m_PingPongTree.isPartitioned = false;
    
    m_PingPongTree.parent = NULL;
    m_PingPongTree.left   = NULL;
    m_PingPongTree.mid    = NULL;
    m_PingPongTree.right  = NULL;
   
    m_NodePool.pNext = NULL;
    m_NodePool.pTreeNode = NULL;
    
    m_BacktrackStack.pNext = NULL;
    m_BacktrackStack.pTreeNode = NULL;
}


// ---------------------------------------------------------------
// Function: CleanTree
//
// Clean all memory allocated for building the Ping-Pong Tree.
//
//
void ChinesePingPong::CleanTree()
{
    ListNode_t * temp = m_NodePool.pNext;
    
    while (temp != NULL)
    {
        m_NodePool.pNext = temp->pNext;
        
        // C style
        // free(temp->pTreeNode);
        // free(temp);
        //
        // C++ style
        delete (temp->pTreeNode);
        delete (temp);
        
        temp = m_NodePool.pNext;
    }
    
    m_NodePool.pNext = NULL;
    m_NodePool.pTreeNode = NULL;
    
    return;
}

// --------------------------------------------------------------
// Function: AddOneToList
//
// Creating one tree node, allocating memory from heap. The function
// returns the new node pointer added/pushed to the given list or pool.
// 
BallGroup_t* ChinesePingPong::AddOneToList(ListNode_t* pPool)
{
    if (pPool == NULL)
        return NULL;
        
    // the new list node and tree node 
    //
    // C style
    //
    // ListNode_t * temp = (ListNode_t *) malloc(sizeof(ListNode_t));
    // temp->pTreeNode = (BallGroup_t*) malloc(sizeof(BallGroup_t));
    //
    //
    // C++ style
    //
    ListNode_t * temp = (ListNode_t *) new ListNode_t;
    temp->pTreeNode = (BallGroup_t*) new BallGroup_t;
    
    (temp->pTreeNode)->isPartitioned = false;
    
    temp->pTreeNode->left = NULL;
    temp->pTreeNode->mid = NULL;
    temp->pTreeNode->right = NULL;
    
    // insert the new node to the beginning of the list
    temp->pNext = pPool->pNext;
    pPool->pNext = temp;
    
    return (pPool->pNext->pTreeNode);
}

// ----------------------------------------------------------------
// Function: FindOneFromList
//
// Find the next TreeNode that has been generated but not 
// partitioned yet. It does not pop out or delete the node.
//
BallGroup_t* ChinesePingPong::FindOneFromList(ListNode_t* pPool)
{
    if (pPool == NULL)
        return NULL;
        
    ListNode_t* temp =  pPool->pNext;
    
    while (temp != NULL)
    {
        if ((temp->pTreeNode)->isPartitioned)
        {
            temp = temp->pNext;
        }
        else break;
    }
    
    if (temp == NULL)
    {
        return (BallGroup_t*) NULL;
    }
    
    return temp->pTreeNode;
}



// --------------------------------------------------------------
// Function: Push
//
// Push one item to the stack.
//
void ChinesePingPong::Push(BallGroup_t* pGroup)
{
    ListNode_t* temp = new ListNode_t;
    
    temp->pTreeNode = pGroup;
    temp->pNext = m_BacktrackStack.pNext;
    
    m_BacktrackStack.pNext = temp;
    
    return;
}

// ---------------------------------------------------------------
// Function: Pop
//
// Pops out the top item from the stack.
//
BallGroup_t* ChinesePingPong::Pop(void)
{
    ListNode_t* temp = m_BacktrackStack.pNext;
    
    if (temp == NULL)
        return NULL;
    
    BallGroup_t* retItem = temp->pTreeNode;
    m_BacktrackStack.pNext = temp->pNext;
    delete temp;
    
    return retItem;
}



// ---------------------------------------------------------------
// Function: PartitionGroup
//
// Partition a given group into three or two groups. This is the core
// part of the algorithm.  To find the bad ball, a group may be 
// partitioned hierarchically into smaller and smaller sub-groups, or
// tested many times. But, eventually, when the sub-group has only
// one ball, the solution is reached.
//
// return: number of sub-groups partitioned.
//
int ChinesePingPong::PartitionGroup(BallGroup_t *pGroup)
{
    int numGroups = 0;
    int grp1 = 0;
    int grp2 = 0;
    int grp3 = 0;
    int M    = 0;
    int newLevel = 0;
    
    if (pGroup == NULL) 
    {
        return 0;
    }
    
    //
    // When a group is NOT partitioned, it means that these balls as in such a 
    // group has NOT been tested in the scale. After a group is partitioned
    // into sub-groups, it is then considered as tested; then the group tree
    // go down to its children, and so on.  Finally, from the leaf to the root,
    // the length of the path represents the total number of tests for one of the
    // possible cases. Each group has a "level" variable to indicate its level
    // in the group tree or the solution tree.  
    //
    // The length of the longest path from a sub-group to the root is recorded 
    // in the variable:  m_minTestsRequired
    // 
    if (pGroup->isPartitioned == true)
    {
        if (debug) 
            printf("The group is already partitioned!\n");

        return 0;
    }
    
    M = pGroup->totalNum;
    newLevel = pGroup->level +1;
    
    if (M <= 1)
    {
        // We are done. The solution is reached for this case.
        pGroup->isPartitioned = true;
        return 0;
    }

    // Step 1: Determine how many sub-groups and their sizes: 
    //            - calculate the basic group size and the remainder
    //            - determine the number of sub-groups
    //            - finalize the sub-group size by assigning the remainder
    //
    unsigned int divSize = M/3;
    unsigned int remainder = M % 3;
    
    if (pGroup->isTested)
    {
        // This sub-group has been tested or is the one on the scale currently;
        // but it needs more tests or further partitioned to find the bad ball.
        //
        // It can be divided into 3 sub-groups. If a group is isTested, its sub-groups
        // will remain as "isTested" status; and it can still be further divided into 
        // 3 sub-groups; and so on so forth.
        // 
        numGroups = 3;
        grp1 = divSize;
        grp2 = divSize;
        grp3 = divSize;
    }
    else
    {
       // 
       // This sub-group was put aside from the scale, which has never been tested.
       // In this case, always partition into two groups: grp1 and grp2.
       // grp1 takes 2/3 of balls to be put on the scale to test, and grp2 takes 1/3 
       // of balls to remain outside, waiting to be tested.
       //       
       numGroups = 2;
       grp1 = divSize + divSize;
       grp2 = divSize;
       grp3 = 0;
    }
    
    // We need to add the remainder to some groups;
    // and we want to make sure that at least one group
    // has even number of balls (grp1 in this case)
    // when it is at level 1 (the very first partition).
    // However, after more tests, we don't have to keep
    // it even because we can use Theorem 2 to add dummy balls.
    if (remainder == 1)
    {
        // we want to put the remainder into the scale
        // if this is not the very first partition.
        if (numGroups == 2)
        {  
           if (pGroup->level == 0)
           {
              // Put the ball in the group outside the scale
              grp2++;
           }
           else
           {
              // Put the ball in the group inside the scale
              grp1++;
           }
        }
        else if (numGroups == 3) 
        {
           // Put the ball into the group inside the scale
           grp1++;
        }
    }
    else if (remainder == 2)
    {
        // In general, try to spread the two balls in two different groups.
        
        if (numGroups == 2)
        {
           // This is a group that has been put aside and now partition into two.
           // We want to put only one ball onto the scale; keep the other ball
           // in a different sub-group; except a special case.
           
           if (pGroup->level == 0)
           {  
              // Special case:  This is the whole-group that has never been
              // partitioned yet. Then, put both balls to the scale to test.
              // in order to keep two sides even.
              grp1 = grp1 + 2; 
           }
           else
           {
              // These cases including a sub-group of 5 balls partitioned  
              // from a larger group, but it has never been put onto the
              // scale to test. This group can be partitioned into
              // 2-1-2 so that they can be tested by only 2 times
              // instead of 3 times in order to find the bad ball.
              // 
              // So, we put 2+1 to grp1 going to the scale, and
              // put 1+1 in grp2 that is put outside the scale.   
              grp1++;
              grp2++;
           }
        }
        else if (numGroups == 3) 
        {
           // we want to put both balls onto the scale,
           // and put them in each of two sub-groups.
           grp1++;
           grp2++;
        }
    }
    
    // Step 2: create the sub-groups and grow the tree
    // -----------------------------------------------
    if (numGroups == 3)
    {
        // These are the cases that the group, from two sides of the scale,
        // have just been measured or "isTested", and found that they are NOT 
        // balanced. Therefore, we can divide them into three sub-groups.
        //
        BallGroup_t* g1 = AddOneToList(&m_NodePool);
        BallGroup_t* g2 = AddOneToList(&m_NodePool);
        BallGroup_t* g3 = AddOneToList(&m_NodePool);
        
        // make a family tie
        g1->totalNum = grp1;
        g1->level = newLevel;
        g1->parent = pGroup;
        g1->isTested = true;
        
        g2->totalNum = grp2;
        g2->level = newLevel;
        g2->parent = pGroup;
        g2->isTested = true;
        
        g3->totalNum = grp3;
        g3->level = newLevel;
        g3->parent = pGroup;
        g3->isTested = true;
        
        pGroup->left  = g1;
        pGroup->mid   = g2;
        pGroup->right = g3;
    }
    else
    {
        // This is the initial case, or the cases that the balls
        // have never been measured yet. So, we can only divide
        // them into 2 groups with "left" group containing 2/3
        // of balls, and "right" group of 1/3 balls.
        // The left group will be put on the scale (or as "isTested"),
        // which will be further divided into 3 sub-groups (as the above case);
        // and the right group remains as NOT isTested (which can only be divided
        // into 2 sub-groups and so on).
        //
        BallGroup_t* g1 = AddOneToList(&m_NodePool);
        BallGroup_t* g2 = AddOneToList(&m_NodePool);
        
        g1->totalNum = grp1;
        g1->level = newLevel;
        g1->parent = pGroup;
        g1->isTested = true;
        
        g2->totalNum = grp2;
        g2->level = 1; 
        g2->parent = pGroup;
        g2->isTested = false;
        
        pGroup->left  = g1;
        pGroup->mid   = NULL;
        pGroup->right = g2;
    }

    pGroup->isPartitioned = true;
    
    if (newLevel > m_minTestsRequired)
    {
        m_minTestsRequired = newLevel;
    }
    
    if (debug) 
        printf("\nGroupID = %p, GroupsSize = %d, numOfSub-Groups = %d, \nGroup1 = %d, Group2 = %d, Group3 = %d\n",
                (void*)pGroup, M, numGroups, grp1, grp2, grp3);
    
    
    return numGroups;
}

// ---------------------------------------------------------------
// Function: BuildTree
//
// Build up a full tree for a given problem of size N.
//
void ChinesePingPong::BuildTree(int N)
{
    m_totalNumBalls = N;
    
    if (m_NodePool.pNext != NULL)
    {
        if (debug) 
            printf("The Ping-Pong Tree is not Clean, some task is not done!\n");
            
        return;
    }
    
    m_PingPongTree.totalNum = N;
    m_PingPongTree.isTested = false;
    m_PingPongTree.level = 0; 
    
    PartitionGroup(&m_PingPongTree);
    
    while (1)
    {
        BallGroup_t* temp = FindOneFromList(&m_NodePool);
        
        if (temp == NULL)
        {
            if (debug) 
                printf("\nReached the end of the list!\n");
                
            break;
        }
        else
        {
            if (debug) 
                printf("\nPartitioned another group ...\n");
                
            PartitionGroup(temp);
        }
    }
    
    return;
}
    
// -----------------------------------------------------------
// Function: FindMinTests
//
// This function return the minimum number of tests needed to 
// find the bad ping-pong in Chinese Ping Pong problem.
//
int ChinesePingPong::FindMinTests(int N)
{
   if (m_totalNumBalls != N)
   {
      CleanTree();
      Init();
      BuildTree(N);
   }
          
   return m_minTestsRequired;
}


// ----------------------------------------------------------
// Function: PrintPath
//
// This function prints a single path from the given leaf to
// the root of the tree.
//
void ChinesePingPong::PrintPath(BallGroup_t *pGroup)
{
    if (pGroup == NULL)
    {
        printf("The given leaf is NULL, PrintPath ignored.\n");
        
        return;
    }
    
    printf("LeafToRoot Path: %d -- ", pGroup->totalNum);
    
    BallGroup_t *temp = pGroup->parent;
    
    while(temp != NULL)
    {
        
        printf("%d -- ", temp->totalNum);
        temp = temp->parent;
    }
    
    printf("##\n");
    
    return;
}


// -----------------------------------------------------------
// Function: PrintTree
//
// Printing the Ping-Pong Tree, which will show all possible
// solutions. Each solution corresponds to the path from the 
// root to the leaf. The number of nodes on this path (not
// including the root) is the number of tests or measurements
// you needed to find the bad ball.
//
void ChinesePingPong::PrintTree(int N)
{
    // Traverse the solution tree, rooted at m_PingPongTree,
    // in depth-first and left-to-right method to visit every
    // leaf of the tree.
    int numPaths = 0;

    if (m_totalNumBalls != N)
    {
        CleanTree();
        Init();
        BuildTree(N);
    }
    
    BallGroup *temp = &m_PingPongTree;
    
    for(;;)
    {
        while ( (temp->left) != NULL)
        {
            if (temp->right != NULL)
            {
                Push(temp->right);
            }
            
            if (temp->mid != NULL)
            {
                Push(temp->mid);
            }
            
            temp = temp->left;
        }
        
        // Now, temp is pointing to a leaf, we found one solution.
        printf("\nSolution %d:  ", ++numPaths);
       	PrintPath(temp);
        
        // check if Backtrack stack is empty or not
        temp = Pop();
        if (temp == NULL)
            break;
            
    } // for(;;)

    
    return;
}


// ---------------------------------------------------------
//
// Testing functions:  N = 3 to 256 balls
//
static void auto_test(ChinesePingPong* pCpp)
{
    printf("\n\n  NumberOfBalls     NumberOfTests   \n");
    printf("-------------------------------------\n\n"); 
        
    for (int i = 3; i<= 256; i++)
    {
        int numTests = pCpp->FindMinTests(i);
        printf("       %d                   %d \n", i, numTests);
    }
};



// ----------------------------------------------------------
//
//                        M A I N
//
// ----------------------------------------------------------
int main(int argc, char* argv[])
{
    ChinesePingPong* cpp = new ChinesePingPong();
    if (cpp == NULL) 
        return -1;
    
    if (argc == 1)
    {
        auto_test(cpp);
        printf("\nAll tests are successfully done ... \n");
    }
    else if (argc == 2)
    {
        int i = atol(argv[1]);
        int numTests = cpp->FindMinTests(i);
        printf("\n   numOfBalls = %d,   numOfTests = %d \n\n", i, numTests);
        
        if (debug) cpp->PrintTree(i);
    }
    else
    {
        printf("Usage: ping-pong <numberOfBalls> \n");
    }
    
    delete cpp;

    return 0;
}
