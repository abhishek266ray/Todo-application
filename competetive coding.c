                                               Practical 1 
MINSTACK which should support 
operations like push, pop, overflow, underflow, display 
a. 
Construct a stack of N-capacity 
a. 
a. 
a. 
a. 
Code : 
import java.util.*; 
class MinStack { 
private int maxSize; 
private Stack<Integer> stack; 
private Stack<Integer> minStack; 
public MinStack(int capacity) { 
maxSize = capacity; 
stack = new Stack<>(); 
minStack = new Stack<>(); 
} 
public void push(int element) { 
if (stack.size() >= maxSize) { 
System.out.println("Overflow"); 
return; 
} 
stack.push(element); 
if (minStack.isEmpty() || element <= minStack.peek()) { 
minStack.push(element); 
} 
} 
public void pop() { 
if (stack.isEmpty()) { 
System.out.println("Underflow"); 
return; 
} 
int popped = stack.pop(); 
if (popped == minStack.peek()) { 
minStack.pop(); 
} 
} 
public int top() { 
if (stack.isEmpty()) { 
System.out.println("Stack is empty"); 
return -1; 
} 
return stack.peek(); 
} 
public int getMin() { 
if (minStack.isEmpty()) { 
System.out.println("Stack is empty"); 
return -1; 
} 
return minStack.peek(); 
} 
public void display() { 
System.out.println("Elements in the stack:"); 
for (int i : stack) { 
System.out.print(i + " "); 
} 
System.out.println(); 
} 
} 
public class Main { 
public static void main(String[] args) { 
MinStack minStack = new MinStack(5); 
minStack.push(3); 
minStack.push(5); 
minStack.push(2); 
minStack.push(7); 
minStack.push(1); 
minStack.display(); 
  
System.out.println("Min element in stack: " + minStack.getMin()); 
minStack.pop(); 
minStack.pop(); 
System.out.println("Top element in stack: " + minStack.top()); 
} 
}
                                         Practical 2 
Aim : Write a program to deal with real-world situations where Stack data structure is 
widely used 
Evaluation of expression: 
Stacks are used to evaluate expressions, especially in 
languages that use postfix or prefix notation. Operators and operands are pushed 
onto the stack, and operations are performed based on the LIFO principle. 

Code : 
package LabQues; 
import java.util.Stack; 
public class ExpressionEvaluation { 
public static int evaluateExpression(String expression) { 
Stack<Integer> stack = new Stack<>(); 
for(char ch : expression.toCharArray()) { 
if(Character.isDigit(ch)) { 
stack.push(Character.getNumericValue(ch)); 
} else { 
int operand2 = stack.pop(); 
int operand1 = stack.pop(); 
switch(ch) { 
case '+': stack.push(operand1 + operand2); break; 
case '-': stack.push(operand1 - operand2); break; 
case '*': stack.push(operand1 * operand2); break; 
case '/': stack.push(operand1 / operand2); break; 
} 
} 
} 
return stack.pop(); 
} 
public static void main(String[] args) { 
String expression = "36+9*"; 
System.out.println("Result: " + evaluateExpression(expression)); 
} 
} 

                                              Practical 3 
Aim : Write a program for finding NGE NEXT GREATER ELEMENT from an array 

Code : 
package LabQues; 
import java.util.*; 
public class NextGreaterElement { 
public static int[] findNextGreaterElement(int[] arr) { 
Stack<Integer> stack = new Stack<>(); 
int n = arr.length; 
int[] result = new int[n]; 
for (int i = n - 1; i >= 0; i--) { 
while (!stack.isEmpty() && stack.peek() <= arr[i]) { 
stack.pop(); 
} 
if (stack.isEmpty()) { 
result[i] = -1; 
} else { 
result[i] = stack.peek(); 
} 
stack.push(arr[i]); 
} 
return result; 
} 
public static void main(String[] args) { 
int[] arr = {4, 3, 2, 1, 5}; 
int[] nge = findNextGreaterElement(arr); 
System.out.println("Next Greater Elements:"); 
for (int i : nge) { 
System.out.print(i + " "); 
} 
} 
} 

                                                  Practical 4 
Aim : Write a program to design a circular queue(k) which Should implement the below 
functions 
Enqueue 
Dequeue 
Front 
Rear 
 
Code : 
package LabQues; 
class CircularQueue { 
private int[] queue; 
private int front, rear, size, capacity; 
public CircularQueue(int k) { 
capacity = k; 
queue = new int[k]; 
front = 0; 
rear = -1; 
size = 0; 
} 
public boolean enQueue(int value) { 
if (!isFull()) { 
rear = (rear + 1) % capacity; 
queue[rear] = value; 
size++; 
return true; 
} 
return false; 
} 
public boolean deQueue() { 
if (!isEmpty()) { 
front = (front + 1) % capacity; 
size--; 
return true; 
} 
return false; 
} 
public int Front() { 
if (!isEmpty()) { 
return queue[front]; 
} 
return -1; 
} 
public int Rear() { 
if (!isEmpty()) { 
return queue[rear]; 
} 
return -1; 
} 
public boolean isEmpty() { 
return size == 0; 
} 
public boolean isFull() { 
return size == capacity; 
} 
public static void main(String[] args) { 
CircularQueue cq = new CircularQueue(5); 
System.out.println(cq.enQueue(1)); // true 
System.out.println(cq.enQueue(2)); // true 
System.out.println(cq.enQueue(3)); // true 
System.out.println(cq.Front()); 
System.out.println(cq.Rear()); 
// 3 
System.out.println(cq.enQueue(4)); // true 
System.out.println(cq.enQueue(5)); // true 
System.out.println(cq.enQueue(6)); // false 
System.out.println(cq.isFull()); // true 
System.out.println(cq.deQueue()); // true 
System.out.println(cq.deQueue()); // true 
System.out.println(cq.Front()); 
System.out.println(cq.Rear()); 
} 
} 


                                                      Practical 5 
Aim : Write a Program for an infix expression, and convert it to postfix notation. Use a 
queue to implement the Shunting Yard Algorithm for expression conversion. 

Code : 
package LabQues; 
import java.util.*; 
public class InfixToPostfix { 
public static String infixToPostfix(String infix) { 
String postfix = ""; 
Stack<Character> operatorStack = new Stack<>(); 
HashMap<Character, Integer> precedence = new HashMap<>(); 
precedence.put('+', 1); 
precedence.put('-', 1); 
precedence.put('*', 2); 
precedence.put('/', 2); 
precedence.put('^', 3); 
for (char c : infix.toCharArray()) { 
if (Character.isLetterOrDigit(c)) { 
postfix += c; 
} else if (c == '(') { 
operatorStack.push(c); 
} else if (c == ')') { 
while (!operatorStack.isEmpty() && operatorStack.peek() != '(') { 
postfix += operatorStack.pop(); 
} 
operatorStack.pop(); // Pop '(' 
} else { 
while (!operatorStack.isEmpty() && precedence.getOrDefault(c, 0) <= 
precedence.getOrDefault(operatorStack.peek(), 0)) { 
postfix += operatorStack.pop(); 
} 
operatorStack.push(c); 
} 
} 
while (!operatorStack.isEmpty()) { 
postfix += operatorStack.pop(); 
} 
return postfix; 
} 
public static void main(String[] args) { 
String infixExpression = "a+b*(c^d-e)^(f+g*h)-i"; 
System.out.println("Postfix expression: " + infixToPostfix(infixExpression)); 
} 
} 


                                          Practical 6 
Aim : Write a Program for finding the Product of the three largest Distinct Elements. Use 
a Priority Queue to efficiently find and remove the largest elements 

Code : 
package LabQues; 
import java.util.*; 
public class ThreeLargestProduct { 
public static int findProductOfThreeLargest(int[] nums) { 
PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); 
for (int num : nums) { 
pq.offer(num); 
} 
int largest1 = pq.poll(); 
int largest2 = pq.poll(); 
int largest3 = pq.poll(); 
return largest1 * largest2 * largest3; 
} 
public static void main(String[] args) { 
int[] nums = {5, 10, 2, 8, 15, 3}; 
System.out.println("Product of the three largest distinct elements: " + 
findProductOfThreeLargest(nums)); 
} 
} 

                                                      Practical 7 
Aim: write a program to merge two link list.

Code : 
package LabQues; 
class node 
{ 
int data; 
node next; 
node(int data){ 
this.data = data; 
} 
} 
public class MergeTwoSortedList { 
public static node mergeTwoLists(node l1, node l2) { 
node dummy = new node(0); 
node l3 = dummy; 
while (l1 != null && l2 != null) { 
if (l1.data < l2.data) { 
l3.next = l1; 
l1 = l1.next; 
} else { 
l3.next = l2; 
l2 = l2.next; 
} 
l3 = l3.next; 
} 
if(l1 == null){ 
l3.next = l2; 
} 
else{ 
l3.next = l1; 
} 
return dummy.next; 
} 
public static void main(String[] args) { 
node l1 = new node(1); 
l1.next = new node(2); 
l1.next.next = new node(4); 
node l2 = new node(1); 
l2.next = new node(3); 
l2.next.next = new node(4); 
node dummy = mergeTwoLists(l1, l2); 
while(dummy != null){ 
System.out.print(dummy.data + " "); 
dummy = dummy.next; 
} 
} 
} 
 
                                         Practical 8 
Aim : Write a Program to find the Merge point of two linked lists(sorted) 
Code : 
package LabQues; 
class Node { 
int data; 
Node next; 
 
Node(int data) { 
this.data = data; 
} 
} 
public class MergePointLinkedList { 
public static Node findMergePoint(Node l1, Node l2) { 
while (l1 != l2) { 
if (l1.data < l2.data) { 
l1 = l1.next; 
} else if (l1.data > l2.data) { 
l2 = l2.next; 
} else { 
return l1; 
} 
} 
return l1; // or return l2 (since they intersect at the same point) 
} 
public static void main(String[] args) { 
Node intersectNode = new Node(8); 
Node l1 = new Node(1); 
l1.next = new Node(3); 
l1.next.next = new Node(5); 
l1.next.next.next = intersectNode; 
Node l2 = new Node(2); 
l2.next = new Node(4); 
l2.next.next = intersectNode; 
Node mergePoint = findMergePoint(l1, l2); 
if (mergePoint != null) { 
System.out.println("Merge Point: " + mergePoint.data); 
} else { 
System.out.println("No Merge Point found."); 
} 
} 
} 


                                            Practical 9 
Aim: write a program to swap node pairwise
Code : 
package LabQues; 
class node{ 
int data; 
node next; 
node(int data){ 
this.data = data; 
} 
} 
public class SwapNodesInPairs { 
// (data swap) if ask to swap data then use this function 
public static node swap(node head){ 
node l1 = head; 
while (l1 != null && l1.next != null){ 
int temp = l1.data; 
l1.data = l1.next.data; 
l1.next.data = temp; 
l1 = l1.next.next; 
} 
return head; 
} 
// (nodes swap) if ask to swap nodes then use this function 
public static node addressSwap(node head){ 
node l1 = head; 
node dummy = new node(-1); 
dummy.next = l1; 
node point = dummy; 
while(point.next != null && point.next.next != null){ 
node swap1 = point.next; 
node swap2 = point.next.next; 
swap1.next = swap2.next; 
swap2.next = swap1; 
point.next = swap2; 
point = swap1; 
} 
return dummy.next; 
} 
public static void main(String[] args){ 
node l1 = new node(3); 
l1.next = new node(5); 
l1.next.next = new node(4); 
l1.next.next.next = new node(7); 
node head = addressSwap(l1); 
while(head != null){ 
System.out.print(head.data+" "); 
head = head.next; 
} 
} 
} 
                                                      Practical 10 
Aim : Write a Program to Understand and implement Tree traversals i.e. Pre-Order Post- 
Order, In-Order 

Code : 
package LabQues; 
public class TreeTraversals { 
// Node class representing a node in the tree 
static class Node { 
int data; 
Node left, right; 
Node(int data) { 
this.data = data; 
this.left = null; 
this.right = null; 
} 
} 
// Main class with tree creation and traversal methods 
public static void main(String[] args) { 
// Create a sample binary tree 
Node root = new Node(1); 
root.left = new Node(2); 
root.right = new Node(3); 
root.left.left = new Node(4); 
root.left.right = new Node(5); 
// Pre-order traversal (Root -> Left -> Right) 
System.out.print("Pre-order traversal: "); 
preOrderTraversal(root); 
System.out.println(); 
// In-order traversal (Left -> Root -> Right) 
System.out.print("In-order traversal: "); 
inOrderTraversal(root); 
System.out.println(); 
// Post-order traversal (Left -> Right -> Root) 
System.out.print("Post-order traversal: "); 
postOrderTraversal(root); 
System.out.println(); 
} 
// Pre-order traversal method 
public static void preOrderTraversal(Node root) { 
if (root == null) { 
return; 
} 
System.out.print(root.data + " "); // Visit root first 
preOrderTraversal(root.left); 
preOrderTraversal(root.right);  
} 
// In-order traversal method 
public static void inOrderTraversal(Node root) { 
if (root == null) { 
return; 
} 
inOrderTraversal(root.left); 
// Visit left subtree first 
System.out.print(root.data + " "); // Then visit root 
inOrderTraversal(root.right);  
// Then visit right subtree 
} 
// Post-order traversal method 
public static void postOrderTraversal(Node root) { 
if (root == null) { 
return; 
} 
postOrderTraversal(root.left); 
// Visit left subtree first 
postOrderTraversal(root.right);  
// Then visit right subtree 
System.out.print(root.data + " "); // Then visit root 
} 
} 

                                           Practical 11 
Aim : Write a Program to verify and validate mirrored trees or not 

Code : 
package LabQues; 
public class VerifyMirroredTrees { 
// Node class representing a node in the tree 
static class Node { 
int data; 
Node left, right; 
Node(int data) { 
this.data = data; 
this.left = null; 
this.right = null; 
} 
} 
// Method to check if two trees are mirror images 
public static boolean areMirror(Node root1, Node root2) { 
// Base case: Both trees are empty 
if (root1 == null && root2 == null) { 
return true; 
} 
// One tree is empty and the other is not 
if (root1 == null || root2 == null) { 
return false; 
} 
// Check if root data matches and subtrees are mirrors 
return root1.data == root2.data && 
areMirror(root1.left, root2.right) && 
areMirror(root1.right, root2.left); 
}  
// Main method for creating sample trees and checking if they are mirrored 
public static void main(String[] args) { 
// Create mirrored trees 
Node root1 = new Node(1); 
root1.left = new Node(2); 
root1.right = new Node(3); 
root1.left.left = new Node(4); 
root1.left.right = new Node(5); 
Node root2 = new Node(1); 
root2.left = new Node(3); 
root2.right = new Node(2); 
root2.right.left = new Node(5); 
root2.right.right = new Node(4); 
// Check if the trees are mirror images 
boolean mirrored = areMirror(root1, root2); 
if (mirrored) { 
System.out.println("Given trees are mirrored trees."); 
} else { 
System.out.println("Given trees are not mirrored trees."); 
} 
} 
} 

                                       Practical 12 
Aim : Write a Program to determine the depth of a given Tree by Implementing 
MAXDEPTH 

Code : 
package LabQues; 
public class TreeDepth { 
// Node class representing a node in the tree 
static class Node { 
int data; 
Node left, right; 
Node(int data) { 
this.data = data; 
this.left = null; 
this.right = null; 
} 
} 
// Method to calculate the maximum depth of a tree 
public static int maxDepth(Node root) { 
if (root == null) { 
return 0; // Empty tree has depth 0 
} 
// Recursively find depths of left and right subtrees 
int leftDepth = maxDepth(root.left); 
int rightDepth = maxDepth(root.right); 
// Return the larger depth + 1 (for the current node) 
return Math.max(leftDepth, rightDepth) + 1; 
} 
// Main method for creating a sample tree and calculating its depth 
public static void main(String[] args) { 
// Create a sample binary tree 
Node root = new Node(1); 
root.left = new Node(2); 
root.right = new Node(3); 
root.left.left = new Node(4); 
root.left.right = new Node(5); 
// Calculate and print the depth of the tree 
int depth = maxDepth(root); 
System.out.println("Depth of the tree: " + depth); 
} 
} 

                                                Practical 13 
Aim: write a program for lowest common ancestor.
Code : 
package LabQues; 
public class LowestCommonAncestor { 
// Node class representing a node in the tree 
static class Node { 
int data; 
Node left, right; 
Node(int data) { 
this.data = data; 
this.left = null; 
this.right = null; 
} 
} 
// Method to find the Lowest Common Ancestor (LCA) of two nodes 
public static Node findLCA(Node root, int n1, int n2) { 
// Base case: Empty tree or root matches one of the nodes 
if (root == null || root.data == n1 || root.data == n2) { 
return root; 
} 
// Recursively search for n1 and n2 in left and right subtrees 
Node leftLCA = findLCA(root.left, n1, n2); 
Node rightLCA = findLCA(root.right, n1, n2); 
// If both left and right subtrees found a node, then root is LCA 
if (leftLCA != null && rightLCA != null) { 
return root; 
} 
// Return the only node found (if one is in left and the other in right) 
return (leftLCA != null) ? leftLCA : rightLCA; 
} 
// Main method to create a sample tree and find LCA 
public static void main(String[] args) { 
// Create a sample binary tree 
Node root = new Node(1); 
root.left = new Node(2); 
root.right = new Node(3); 
root.left.left = new Node(4); 
root.left.right = new Node(5); 
root.right.left = new Node(6); 
root.right.right = new Node(7); 
// Find LCA of nodes 4 and 7 
int n1 = 4, n2 = 7; 
Node lca = findLCA(root, n1, n2); 
if (lca != null) {  
System.out.println("LCA of " + n1 + " and " + n2 + " is: " + lca.data); 
} else { 
System.out.println("LCA not found."); 
} 
} 
} 

                                                     Practical 14 
Aim: write a program to build BST.
Code : 
package LabQues; 
public class BST { 
int data; 
BST left; 
BST right; 
public BST(int data){ 
this.data= data; 
} 
} 
class Solution{ 
public static void main(String[] args) { 
BST root = null; 
root = insert(root, 80); 
insert(root, 60); 
insert(root, 90); 
insert(root, 10); 
insert(root, 70); 
insert(root, 85); 
insert(root, 110); 
inorder(root); 
} 
public static BST insert(BST root, int val){ 
if(root == null){ 
return new BST(val); 
} 
if(root.data < val){ 
root.right = insert(root.right, val); 
} 
else{ 
root.left = insert(root.left, val); 
} 
return root; 
} 
public static void inorder(BST root){ 
if(root == null){ 
return; 
} 
inorder(root.left); 
System.out.print(root.data + " "); 
inorder(root.right); 
} 
} 

                                            Practical 16 
Aim : Write a Program to Traverse a Tree using Level Order Traversal 

Code : 
package LabQues; 
import java.util.*; 
public class LevelOrderTraversal { 
// Node class representing a node in the tree 
static class Node { 
int data; 
Node left, right; 
Node(int data) { 
this.data = data; 
this.left = null; 
this.right = null; 
} 
} 

// Method to perform Level Order Traversal using a Queue 
public static void levelOrderTraversal(Node root) { 
if (root == null) { 
return; 
} 
// Create a Queue to store nodes 
Queue<Node> queue = new LinkedList<>(); 
// Add the root node to the queue 
queue.add(root); 
while (!queue.isEmpty()) { 
// Get the current node from the queue 
Node current = queue.poll(); 
// Print the node data 
System.out.print(current.data + " "); 
// Add children to the queue (if any) 
if (current.left != null) { 
queue.add(current.left); 
} 
if (current.right != null) { 
queue.add(current.right); 
} 
} 
} 
// Main method for creating a sample tree and performing traversal 
public static void main(String[] args) { 
// Create a sample binary tree 
Node root = new Node(1); 
root.left = new Node(2); 
root.right = new Node(3); 
root.left.left = new Node(4); 
Enrollment No : 2303051240372 Page | 44 
root.left.right = new Node(5); 
// Perform Level Order Traversal 
System.out.print("Level Order Traversal: "); 
levelOrderTraversal(root); 
System.out.println(); 
} 
} 

                                                 Practical 18 
Aim: write a program to view a tree from left view.

Code : 
package LabQues; 
public class LeftView { 
static class Node { 
int data; 
Node left, right; 
Node(int data) { 
this.data = data; 
this.left = null; 
this.right = null; 
} 
} 
// Recursive function to print the left view of a binary tree 
static void leftViewUtil(Node root, int level, int[] maxLevel) { 
if (root == null) { 
return; 
} 
if (level > maxLevel[0]) { 
System.out.print(root.data + " "); 
maxLevel[0] = level; 
} 
leftViewUtil(root.left, level + 1, maxLevel); 
leftViewUtil(root.right, level + 1, maxLevel); 
} 
// Function to print the left view of a binary tree 
static void leftView(Node root) { 
int[] maxLevel = {0}; // Keep track of the maximum level visited so far 
leftViewUtil(root, 1, maxLevel); 
} 
public static void main(String[] args) { 
Node root = new Node(1); 
root.left = new Node(2); 
root.right = new Node(3); 
root.left.left = new Node(4); 
root.left.right = new Node(5); 
System.out.print("Left view of the tree: "); 
leftView(root); 
} 
} 

 
Practical-19 
Write a Program for a basic hash function in a programming language of your choice. 
Demonstrate its usage to store and retrieve key-value pairs. 
 
 
CODE 
import java.util.*; 
 
 
class BasicHashFunction { 
private static final int SIZE = 100; 
private LinkedList<Pair>[] table; 
 
static class Pair { 
String key; 
int value; 
Pair(String key, int value) { 
this.key = key; 
this.value = value; 
} 
} 
 
 
public BasicHashFunction() { 
table = new LinkedList[SIZE]; 
for (int i = 0; i < SIZE; i++) { 
table[i] = new LinkedList<>(); 
} 
} 
 
 
private int hash(String key) { 
return Math.abs(key.hashCode() % SIZE); 
} 

public void put(String key, int value) { 
int index = hash(key); 
for (Pair pair : table[index]) { 
if (pair.key.equals(key)) { 
pair.value = value; 
return; 
} 
} 
table[index].add(new Pair(key, value)); 
} 
 
 
public Integer get(String key) { 
int index = hash(key); 
for (Pair pair : table[index]) { 
if (pair.key.equals(key)) { 
return pair.value; 
} 
} 
return null; 
} 
 
 
public static void main(String[] args) { 
BasicHashFunction hashTable = new BasicHashFunction(); 
hashTable.put("Alice", 25); 
hashTable.put("Bob", 30); 
hashTable.put("Charlie", 35); 
 
 
System.out.println("Alice's age: " + hashTable.get("Alice")); 
System.out.println("Bob's age: " + hashTable.get("Bob")); 
System.out.println("Charlie's age: " + hashTable.get("Charlie")); 

} 
} 
 

 
                                             Annexure-20 
Write a Program to Implement Two sums using HASHMAP 
CODE 
import java.util.*; 
 
 
public class TwoSumHashMap { 
public static int[] twoSum(int[] nums, int target) { 
Map<Integer, Integer> map = new HashMap<>(); 
for (int i = 0; i < nums.length; i++) { 
int complement = target - nums[i]; 
if (map.containsKey(complement)) { 
return new int[]{map.get(complement), i}; 
} 
map.put(nums[i], i); 
} 
return new int[]{}; 
} 
 
 
public static void main(String[] args) { 
int[] nums = {2, 7, 11, 15}; 
int target = 9; 
int[] result = twoSum(nums, target); 
 
 
if (result.length == 2) { 
System.out.println("Indices: " + result[0] + ", " + result[1]); 
} else { 
System.out.println("No solution found"); 
} 
} 
} 

                                         Annexure-21 
Write a Program to find Distinct substrings in a string 
CODE 
import java.util.*; 
 
 
public class DistinctSubstrings { 
public static Set<String> findDistinctSubstrings(String s) { 
Set<String> substrings = new HashSet<>(); 
int n = s.length(); 
 
 
for (int i = 0; i < n; i++) { 
for (int j = i + 1; j <= n; j++) { 
substrings.add(s.substring(i, j)); 
} 
} 
 
 
return substrings; 
} 
 
 
public static void main(String[] args) { 
String input = "abc"; 
Set<String> result = findDistinctSubstrings(input); 
 
 
System.out.println("Distinct substrings:"); 
for (String str : result) { 
System.out.println(str); 
} 
} 
} 

                                             Annexure-22 
Write a Program to find The No of Words in a Trie. 
CODE 
class TrieNode { 
TrieNode[] children; 
boolean isEndOfWord; 
 
TrieNode() { 
children = new TrieNode[26]; 
isEndOfWord = false; 
} 
} 
 
 
public class Trie { 
private TrieNode root; 
private int wordCount; 
 
 
public Trie() { 
root = new TrieNode(); 
wordCount = 0; 
} 
 
 
public void insert(String word) { 
TrieNode node = root; 
for (char ch : word.toCharArray()) { 
int index = ch - 'a'; 
if (node.children[index] == null) { 
node.children[index] = new TrieNode(); 
} 
node = node.children[index]; 
} 
if (!node.isEndOfWord) { 
node.isEndOfWord = true; 
wordCount++; 
} 
} 
 
 
public int getWordCount() { 
return wordCount; 
} 
 
 
public static void main(String[] args) { 
Trie trie = new Trie(); 
trie.insert("apple"); 
trie.insert("app"); 
trie.insert("banana"); 
trie.insert("bat"); 
trie.insert("apple"); 
 
System.out.println("Number of words in Trie: " + trie.getWordCount()); 
} 
} 
 

                                               Annexure-23 
Implement a hash table using separate chaining for collision handling. Perform operations like insertion, deletion, and 
search on the hash table 
CODE 
import java.util.LinkedList; 
 
 
class HashNode<K, V> { 
K key; 
V value; 
HashNode<K, V> next; 
 
 
public HashNode(K key, V value) { 
this.key = key; 
this.value = value; 
this.next = null; 
} 
} 
 
 
class HashTable<K, V> { 
private LinkedList<HashNode<K, V>>[] buckets; 
private int capacity; 
private int size; 
 
 
public HashTable(int capacity) { 
this.capacity = capacity; 
this.size = 0; 
buckets = new LinkedList[capacity]; 
for (int i = 0; i < capacity; i++) { 
buckets[i] = new LinkedList<>(); 
} 
} 
 
 
private int getHash(K key) { 
return Math.abs(key.hashCode()) % capacity; 
} 
 
 
public void insert(K key, V value) { 
int index = getHash(key); 
for (HashNode<K, V> node : buckets[index]) { 
if (node.key.equals(key)) { 
node.value = value; 
return; 
} 
} 
buckets[index].add(new HashNode<>(key, value)); 
size++; 
} 
 
 
public V search(K key) { 
int index = getHash(key); 
for (HashNode<K, V> node : buckets[index]) { 
if (node.key.equals(key)) { 
return node.value; 
} 
} 
return null; 
} 
 
 
public boolean delete(K key) { 
int index = getHash(key); 
for (HashNode<K, V> node : buckets[index]) { 

if (node.key.equals(key)) { 
buckets[index].remove(node); 
size--; 
return true; 
} 
} 
return false; 
} 
 
 
public void display() { 
for (int i = 0; i < capacity; i++) { 
System.out.print("Bucket " + i + ": "); 
for (HashNode<K, V> node : buckets[i]) { 
System.out.print("[" + node.key + ": " + node.value + "] -> "); 
} 
System.out.println("null"); 
} 
} 
} 
 
 
public class HashTableDemo { 
public static void main(String[] args) { 
HashTable<String, Integer> hashTable = new HashTable<>(10); 
 
 
hashTable.insert("apple", 50); 
hashTable.insert("banana", 30); 
hashTable.insert("cherry", 40); 
hashTable.insert("apple", 60); 
 
 
hashTable.display(); 

System.out.println("Search 'banana': " + hashTable.search("banana")); 
System.out.println("Search 'grape': " + hashTable.search("grape")); 
 
System.out.println("Delete 'banana': " + hashTable.delete("banana")); 
System.out.println("Delete 'grape': " + hashTable.delete("grape")); 
 
hashTable.display(); 
} 
} 
 
                                          Annexure-24 
Write a Program to Implement Search, insert, and remove in Trie. 
CODE 
class TrieNode { 
TrieNode[] children; 
boolean isEndOfWord; 
 
public TrieNode() { 
children = new TrieNode[26]; 
isEndOfWord = false; 
} 
} 
 
 
public class TrieSEA { 
private TrieNode root; 
 
public TrieSEA() { 
root = new TrieNode(); 
} 
 
 
public void insert(String word) { 
TrieNode node = root; 
for (char ch : word.toCharArray()) { 
int index = ch - 'a'; 
if (node.children[index] == null) { 
node.children[index] = new TrieNode(); 
} 
node = node.children[index]; 
} 
node.isEndOfWord = true; 

} 
 
 
public boolean search(String word) { 
TrieNode node = root; 
for (char ch : word.toCharArray()) { 
int index = ch - 'a'; 
if (node.children[index] == null) { 
return false; 
} 
node = node.children[index]; 
} 
return node.isEndOfWord; 
} 
 
 
public boolean remove(String word) { 
return delete(root, word, 0); 
} 
 
 
private boolean delete(TrieNode node, String word, int depth) { 
if (node == null) return false; 
 
if (depth == word.length()) { 
if (!node.isEndOfWord) return false; 
node.isEndOfWord = false; 
return isEmpty(node); 
} 
 
 
int index = word.charAt(depth) - 'a'; 
if (delete(node.children[index], word, depth + 1)) { 
node.children[index] = null; 
return !node.isEndOfWord && isEmpty(node); 

} 
return false; 
} 
 
 
private boolean isEmpty(TrieNode node) { 
for (TrieNode child : node.children) { 
if (child != null) return false; 
} 
return true; 
} 
 
 
public static void main(String[] args) { 
Trie trie = new TrieSEA(); 
trie.insert("apple"); 
trie.insert("bat");  
trie.insert("ball"); 
 
System.out.println("Search 'apple': " + trie.search("apple")); 
System.out.println("Search 'bat': " + trie.search("bat")); 
System.out.println("Search 'cat': " + trie.search("cat")); 
 
System.out.println("Remove 'bat': " + trie.remove("bat")); 
System.out.println("Search 'bat': " + trie.search("bat")); 
 
System.out.println("Remove 'apple': " + trie.remove("apple")); 
System.out.println("Search 'apple': " + trie.search("apple")); 
} 
} 

 
                                       Annexure-25 
Write a Program to Implement Huffman coding. 
CODE 
import java.util.*; 
 
 
class HuffmanNode { 
char ch; 
int freq; 
HuffmanNode left, right; 
 
 
public HuffmanNode(char ch, int freq) { 
this.ch = ch; 
this.freq = freq; 
this.left = this.right = null; 
} 
} 
 
 
class HuffmanComparator implements Comparator<HuffmanNode> { 
public int compare(HuffmanNode a, HuffmanNode b) { 
return a.freq - b.freq; 
} 
} 
 
 
public class HuffmanCoding { 
private Map<Character, String> huffmanCodes = new HashMap<>(); 
private HuffmanNode root; 
 
public void buildHuffmanTree(String text) { 
if (text == null || text.isEmpty()) return; 

Map<Character, Integer> freqMap = new HashMap<>(); 
for (char ch : text.toCharArray()) { 
freqMap.put(ch, freqMap.getOrDefault(ch, 0) + 1); 
} 
 
 
PriorityQueue<HuffmanNode> pq = new PriorityQueue<>(new HuffmanComparator()); 
for (Map.Entry<Character, Integer> entry : freqMap.entrySet()) { 
pq.add(new HuffmanNode(entry.getKey(), entry.getValue())); 
} 
 
 
while (pq.size() > 1) { 
HuffmanNode left = pq.poll(); 
HuffmanNode right = pq.poll(); 
HuffmanNode newNode = new HuffmanNode('-', left.freq + right.freq); 
newNode.left = left; 
newNode.right = right; 
pq.add(newNode); 
} 
 
 
root = pq.poll(); 
generateHuffmanCodes(root, ""); 
} 
 
 
private void generateHuffmanCodes(HuffmanNode node, String code) { 
if (node == null) return; 
if (node.left == null && node.right == null) { 
huffmanCodes.put(node.ch, code); 
} 
generateHuffmanCodes(node.left, code + "0"); 
generateHuffmanCodes(node.right, code + "1"); 
} 

public String encode(String text) { 
StringBuilder encodedText = new StringBuilder(); 
for (char ch : text.toCharArray()) { 
encodedText.append(huffmanCodes.get(ch)); 
} 
return encodedText.toString(); 
} 
 
 
public String decode(String encodedText) { 
StringBuilder decodedText = new StringBuilder(); 
HuffmanNode current = root; 
for (char bit : encodedText.toCharArray()) { 
current = (bit == '0') ? current.left : current.right; 
if (current.left == null && current.right == null) { 
decodedText.append(current.ch); 
current = root; 
} 
} 
return decodedText.toString(); 
} 
 
 
public void printHuffmanCodes() { 
System.out.println("Huffman Codes:"); 
for (Map.Entry<Character, String> entry : huffmanCodes.entrySet()) { 
System.out.println("'" + entry.getKey() + "' -> " + entry.getValue()); 
} 
} 
 
 
public static void main(String[] args) { 
HuffmanCoding huffman = new HuffmanCoding(); 

String text = "huffman coding in java"; 
 
 
huffman.buildHuffmanTree(text); 
huffman.printHuffmanCodes(); 
 
String encodedText = huffman.encode(text); 
System.out.println("\nEncoded Text: " + encodedText); 
 
String decodedText = huffman.decode(encodedText); 
System.out.println("Decoded Text: " + decodedText); 
} 
} 
