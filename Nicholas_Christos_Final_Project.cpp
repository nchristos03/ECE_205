#include <iostream>
#include <stack>

using namespace std;

//Declare global variables
string pOrder;

//Structure for a binary tree
struct TreeNode
{
    string data;
    TreeNode* left;
    TreeNode* right;
};

//Function that returns a new pointer to a tree structure with a root with data
TreeNode* createBranch(string data)
{
    TreeNode* newBranch = new TreeNode();
    newBranch->data = data;
    newBranch->left = newBranch->right = nullptr;
    return newBranch;
}

//Return a string that contains an equation gathered from the user
string getEquation()
{
    string equ;

    cout << "Please enter an equation: ";
    getline(cin, equ);

    return equ;
}

//Returns true if the charachter inputted is a digit and false otherwise
bool isDigit(char a)
{
    if(a >= '0' && a <= '9')
        return true;

    return false;
}

//Function returns the a higher value for the more precedence of the operator
int precedence(char op)
{
    if(op == '^')
        return 3;
    else if(op == '/' || op == '*')
        return 2;

    return 1;
}

//Returns true if the charachter inputted is an operator and false otherwise
bool isOperator(char op)
{
    if(op == '^' || op == '/' || op == '*' || op == '+' || op == '-')
        return true;
    
    return false;
}

//Return a string containing the post fix version of the given infix equation
string conToPost(string equ)
{
    stack<char> op;
    string results;

    for(int i = 0; i < equ.length(); i++)
    {
        char holder = equ[i];

        if(holder == ' ')
            continue;
        else if(isDigit(holder))
        {
            while(i < equ.length() && isDigit(equ[i]))
            {
                results += equ[i];
                i++;
            }

            results += ' ';
            i--;
        }
        else if(holder == '(')
            op.push(holder);
        else if(holder == ')')
        {
            while(!op.empty() && op.top() != '(')
            {
                results += op.top();
                results += ' ';
                op.pop();
            }

            if(!op.empty())
                op.pop();
        }
        else
        {
            while(!op.empty() && op.top() != '(' && precedence(holder) <= precedence(op.top()))
            {
                results += op.top();
                results += ' ';
                op.pop();
            }

            op.push(holder);
        }
    }

    while(!op.empty())
    {
        results += op.top();
        results += ' ';
        op.pop();
    }



    return results;
}

//Return a pointer to the root of a binary tree of the given post fix equation
TreeNode* conTree(string result)
{
    stack<TreeNode*> op;
    TreeNode* b, * b1, * b2;

    for(int i = 0; i < result.length(); i++)
    {
        if(result[i] == ' ')
            continue;
        else if(isDigit(result[i]))
        {
            string holder;
            
            while(i < result.length() && isDigit(result[i]))
            {
                holder += result[i];
                i++;
            }
            
            b = createBranch(holder);
            op.push(b);
            i--;
        }
        else if(isOperator(result[i]))
        {
            string holder;

            holder += result[i];

            b = createBranch(holder);

            b1 = op.top();
            op.pop();
            b2 = op.top();
            op.pop();

            b->right = b1;
            b->left = b2;

            op.push(b);
        }
    }

    b = op.top();
    op.pop();

    return b;
}

//Creates a post fix equation by doing a post order transversal of a given binary tree
void postOrder(TreeNode* root, bool first)
{
    if(root != nullptr)
    {
        postOrder(root->left, false);
        postOrder(root->right, false);

        if(first)
            pOrder += root->data;
        else
        {
            pOrder += root->data;
            pOrder += ' ';
        }
    }
    
}

/* Goes through a binary tree that contains the given equation 
   and uses a stack to calculate that equation and place the solution at the top */
void evaluate(stack<int>& val, TreeNode* root)
{
    if(root != nullptr)
    {
        evaluate(val, root->left);
        evaluate(val, root->right);

        if(isDigit(root->data[0]))
            val.push(stoi(root->data));
        else
        {
            int b = val.top();
            val.pop();
            int a = val.top();
            val.pop();

            if(root->data == "*")
                val.push(a*b);
            else if(root->data == "/")
                val.push(a/b);
            else if(root->data == "+")
                val.push(a+b);
            else
                val.push(a-b);
        }
    }
}

int main()
{
    //Declare variables
    string equ, post;
    TreeNode* root;
    stack<int> value;

    equ = getEquation();
    post = conToPost(equ);
    root = conTree(post);
    postOrder(root, true);
    evaluate(value, root);

    //Output results
    cout << pOrder << endl;
    cout << value.top();

    return 0;
}