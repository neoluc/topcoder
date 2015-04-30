
var hackerRank = {};

hackerRank.warmUp = {};
hackerRank.arrayAndSort = {};
hackerRank.search = {};

hackerRank.warmUp.shalockAndSquare = function(){
	var lines = input.split('\n');
    var T = lines.shift();
    
    var search = function(a, target, left, right, findMin){
        while(left <= right){
            var mid = Math.floor((right + left)/2);
            if(a[mid] == target){
                return mid;
            }else if(a[mid] < target){
                left = mid + 1;
            }else if(target <= a[mid]){
                right = mid - 1;
            }
        }
        
        if(findMin){
            return target > a[mid] ? mid+1 : mid;
        }else{
            return target > a[mid] ? mid : mid-1;
        }
        return -1;
    };
    
    
    var squares = [];
    var sqLength = 0;
    
    for(var i=0; i<T; i++){
        var line = lines[i].split(' ');
        var min = line[0];
        var max = line[1];
        
        var j = sqLength + 1;
        while((j*j)<=max){
            squares.push(j*j);
            sqLength++;
            j++;
        }
        

        var answerMin = search(squares, min, 0, sqLength - 1, true);
        var answerMax = search(squares, max, 0, sqLength - 1, false);

        var answer = answerMax - answerMin + 1;
        
        console.log(answer);
        
    }

};

hackerRank.arrayAndSort.problemInsertionSort = function(){

	// start from the second item	
	for(var i=1; i<T; i++){
        // take out the current item as temp
        var temp = a[i];
        
		// compare the current item with items on the left
        for(var j=i-1; j>=0; j--){
            // if right is bigger than left, no need continue
            if(a[j] <= temp){
                break;
            }

            // copy it to the right to create space for current item to insert after this loop stop
            a[j+1] = a[j];
        }

        // push the temp to this right location
        a[j+1] = temp;
    }

};

hackerRank.arrayAndSort.problemQuickSort = function(){

	var swap = function(a, i, j){
	    var temp = a[i];
	    a[i] = a[j];
	    a[j] = temp;
	    return a;
	};

	var partition = function(a, l, r){
	    var p = l;
	    while(l != r){
	        if(p == l){
	            while(a[p] <= a[r] && p<=r-1){
	                r--;
	            }
	            a = swap(a, l, r);
	            p = r;
	            continue;
	        }
	    
	        if(p == r){
	            while(a[l] < a[p] && l+1<=p){
	                l++;
	            }
	            a = swap(a, l, r);
	            p = l;
	            continue;
	        }
	    }
	    return p;
	};

	var quicksort = function(a, l, r){

	    var p = partition(a, l, r);

	    if(l < p-1){
	        qsort(a, l, p-1);
	    }

	    if(p < r){
	        qsort(a, p+1, r);
	    }

	    return a;
	};			

	var a = [5,7,6,4,1,3,3,3];

	console.log(quicksort(a, 0, a.length-1));

};

hackerRank.arrayAndSort.problemCountingSort = function(){

	var input = '
		20
		0 ab
		6 cd
		0 ef
		6 gh
		4 ij
		0 ab
		6 cd
		0 ef
		6 gh
		0 ij
		4 that
		3 be
		0 to
		1 be
		5 question
		1 or
		2 not
		4 is
		2 to
		4 the
	';

    var lines = input.split('\n');
    var n = lines.shift();
    
    var countArray = [];
    
    for(var i=0; i<100; i++){
        countArray[i] = 0;
    }
    
    for(var i=0; i<n; i++){
        var a = lines[i].split(' ');
        var num = a[0];
        var word = a[1];
        countArray[num]++;
    }
    
    console.log(countArray.join(','));
    
    var count = 0;
    var positionArray = [];
    
    for(var i=0; i<100; i++){
        count += countArray[i];
        positionArray.push(count);
    }
    
    console.log(positionArray.join(','));

    var finalArray = [];
    
    for(var i=n-1; i>=0; i--){
        var a = lines[i].split(' ');
        var num = a[0];
        var word = a[1];
        
        var position = positionArray[num] - 1;
        while(typeof finalArray[position] != 'undefined'){
            position -= 1;
        }
        finalArray[position] = word;
    }
    
    console.log(finalArray.join(','));


};

hackerRank.arrayAndSort.problemAnagram = function(){
	// find the minimum number to make two string become anagram
	// convert to acsii
	// count frequency
};

hackerRank.arrayAndSort.insertionSortAdvancedAnalysis = function(){

	// binary tree method
    
    function Node(value){
        this.left = null;
        this.right = null;
        this.value = value;
        this.existCount = 1; // number of same valued node 
        this.customCount = 1; // number of nodes in right subtree plus itself
    }
    
    Node.prototype.incrementCustomCount = function(){
        this.customCount ++;
    };

    Node.prototype.incrementExistCount = function(){
        this.existCount ++;
    };
    
    function BinarySearchTree(){
        this.root = null;
        this.inversionCount = 0;
    }

    BinarySearchTree.prototype.insert = function(node){
    	// insert node if no root
        if(this.root == null){
            this.root = node;
        
        }else{
            current = this.root;
            while(true){
                if(node.value < current.value ){
                    this.inversionCount += current.customCount;
                    if(current.left == null){
                        current.left = node;
                        break;
                    }else{
                        current = current.left;    
                    }
                    
                }else if(node.value > current.value){
                    current.incrementCustomCount();
                    if(current.right == null){
                        current.right = node;
                        break;
                    }else{
                        current = current.right;
                    }
                    
                }else{
                    this.inversionCount += (current.customCount - current.existCount);
                    current.incrementCustomCount();
                    current.incrementExistCount();
                    break;
                }
                
            }
        }
    };
    
    
    for(var i=0; i<T*2; i+=2){
        var n = parseInt(lines[i]);
        var a = lines[i+1].split(' ').map(function(x){return parseInt(x);});
        
        var tree = new BinarySearchTree();
        
        for(var j=0; j<n; j++){
            var node = new Node(a[j]);
            tree.insert(node);
        }
        
        console.log(tree.inversionCount);
    }

}


function rangeSegmentTreeImplementation(){


    var createSegmentTree = function(a){

        var aLength = a.length;
        var treeHeight = Math.ceil(Math.log(aLength)/Math.log(2));
        var treeLength = 2*Math.pow(2, treeHeight) - 1;
        var tree = [];

        function construct(node, start, end){
            if(start == end){
                // console.log('node', node, 'a[start]', a[start]);
                tree[node] = a[start];
            }else{

                var mid = Math.floor( (start + end)/2 );

                // console.log('start', start, 'end', end, 'mid', mid, 'node', node, 'nextleft', node*2, 'nextright', node*2+1);

                construct( node*2, start, mid);
                
                construct( node*2 + 1, mid + 1, end);

                // console.log('one', tree[node*2], 'two', tree[node*2 + 1]);

                tree[node] = tree[node*2] + tree[node*2 + 1];

                // console.log('node', node, 'tree[node]', tree[node]);
                // console.log('----------');
            }

        };
        construct(1, 0, aLength - 1);

        // remember: node=treeIndex, start&end=aIndex
        function query(node, start, end, i, j){
            // console.log('node', node, 'start', start, 'end', end);
            if(j < start || end < i){ // if start end exceed query range, two rangel has no overlapping
                // console.log('exceed', start, end);           
                return 0;
            }

            if(i <= start && end <= j){ // if start end within query range
                // console.log('node tree[node]', node, tree[node]);
                return tree[node];
            }

            var mid = Math.floor( (start + end)/2 );

            var left = query(node*2, start, mid, i, j);
            var right = query(node*2 + 1, mid + 1, end, i, j);

            // console.log('left right', left, right);

            return left + right;
        }


        function update(node, start, end, index, diff){

            // if not within range then return
            if(index < start || end < index){
                return;
            }

            // within range, update node
            tree[node] += diff;

            // extend to child if have not reach child
            if(start != end){

                var mid = Math.floor((start + end)/2);

                update(node*2, start, mid, index, diff);
                update(node*2+1, mid+1, end, index, diff);

            }

        }

        // the update function that for a range
        function rangeUpdate(node, l, r, i, j, diff){

            if( i < l || r < j || r < l){
                return;
            }

            if( l == r){
                tree[node] += diff;
                return;
            }

            var mid = Math.floor( (l + r)/2 );

            update(node*2, l, mid, i, j, diff);

            update(node*2 + 1, mid+1, r, i, j, diff);

            tree[node] = tree[node*2] + tree[node*2 + 1];
        }

        function lazyUpdate(node, l, r, i, j, diff){

            if(lazy[node] != 0){

                tree[node] += lazy[node];

                if(l != r){
                    lazy[node*2] += lazy[node];
                    lazy[node*2 + 1] += lazy[node];
                }

                lazy[node] = 0;
            }

            // if conpletely out of range
            if( i < l || r < j || r < l ){
                return;
            }

            // if completely inside range
            if( i <= l && r <= j){
                tree[node] += diff;

                if( l != r ){
                    lazy[node*2] += diff;
                    lazy[node*2 +1] += diff;
                }

                return;
            }


            var mid = Math.floor( (l+r)/2 );

            // if partially inside range
            lazyUpdate(node*2, l, mid, i, j, diff);
            lazyUpdate(node*2 + 1, mid+1, r, i, j, diff);

            tree[node] = tree[node*2] + tree[node*2 + 1];

        }

        function lazyQuery(node, l, r, i, j){

            if( j < l || r < i ){ // two range has no overlapping
                return 0;
            }

            if(lazy[node] != 0){
                tree[node] += lazy[node];

                if( l != r){
                    lazy[node*2] += lazy[node];
                    lazy[node*2 +1] += lazy[node];
                }

                lazy[node] = 0;
            }

            if( i <= l && r <= j ){ // current range within query range
                return tree[node];
            }

            var mid = Math.floor( (l+r)/2 );

            return lazyQuery(node*2, l, mid, i, j) + lazyQuery(node*2+1, mid+1, r, i, j);
        }


        return {
            query: function(i, j){
                console.log('i j', i, j);
                return query(1, 0, aLength - 1, i, j);
            },

            update: function(index, value){
                var diff = value - a[index];
                a[index] = value;
                update(1, 0, aLength - 1, diff, index);
            },

            getTree:function(){
                return tree;
            }
        };
    };


    var segmentTree = createSegmentTree([1, 3, 5, 7, 9, 11]);

    console.log(segmentTree.getTree());

    console.log(segmentTree.query(1, 4));

    console.log(segmentTree.update(1, 1));

    console.log(segmentTree.getTree());

};


function recursionExample(){
    var count = 0;
    function hihi(){
        console.log('hihi');
        var temp = count;
        if(count < 10){
            count++;
            hihi();

            console.log('printed', temp);
        }
        console.log('terminated');
    }
    
    hihi();
}



function javascriptOopExample(){
    // start of my trial


    // 3 key about javascript object : private(created by closure), public properties like variable or functions(attached with object literal), prototype

    var nodeFactory = (function(){

        var proto = { // private prototype functions for the factory to create the object
            addPublicCount: function(){
                this.publicCount ++;
            },
            getPublicCount: function(){

                var self = this;

                self.addPublicCount(); // access other prototype function like this

                return this.publicCount;
            }
        };

        return {

            nodePrototype: proto,

            create: function(){

                var privateCount = 2;

                var node = Object.create(proto);
                var node.publicCount = 1; // public variable
                var node.addPrivateCount = function(){ // this cannot be prototype functions since you cannot nest prototype functions inside any specific function scope, which provide closure for the private
                    privateCount ++;
                };
                return node;
            }
        };

    })();


    // demo for inheritance
    var subNodeFactory = (function(){

        // setting up the prototype chain, that is, attached an object to the subobject prototype
        var proto = Object.create(nodeFactory.nodePrototype);

        //subNode.prototype.constructor = subNode; // setting the constructor is only required when some prototype function need to know who to call, that is something like, new this.constructor(xxx);, yet most ot the time not required // this line is for the case that has a named constructor function, so that we can attach it to it's constructor, so cannot apply here


        proto.subGetSomething = function(){
            return 'something';
        };

        proto.subGetPublicCount = function(){
            return this.publicCount;
        };

        return {
            create: function(){

                var subNode = Object.create(proto);


                return subNode;

            }
        };

    })();

    // end

}


function binarySearchForRightMostPosition(){

    // eg. [1, 1, 1, 2, 2] target 1, output position 2
    // [1, 1, 1, 2, 2] target 1.5, output position 2

    var l = -1;
    var r = a.length - 1;

    while(r-l > 1){

        var mid = Math.floor( (l+r)/2 );
        
        if(a[mid] <= target){
            l = mid;
        }else{
            r = mid;
        }

    }

    if(a[l+1] <= target){
        l++;
    }

    return l;

}


function mergeSort(a, aLength){
        
    if(aLength <= 1){
        return a;
    }

    var mid = Math.floor(aLength/2);

    var lSub = [];
    var rSub = [];

    var lSubLength = mid;
    var rSubLength = aLength - mid;

    for(var i=0; i<lSubLength; i++){
        lSub[i] = a[i];
    }
    for(var i=0; i<rSubLength; i++){
        rSub[i] = a[i+lSubLength];
    }

    var l = mergeSort(lSub, lSubLength);
    var r = mergeSort(rSub, rSubLength);

    var lPtr = 0;
    var rPtr = 0;

    var result = [];
    var dPtr = 0;

    while( dPtr < aLength ){

        if(lPtr == lSubLength){

            result[dPtr] = r[rPtr];
            rPtr++;

        }else if(rPtr == rSubLength){

            result[dPtr] = l[lPtr];
            lPtr++;

        }else if( l[lPtr] <= r[rPtr] ){

            result[dPtr] = l[lPtr];
            lPtr++;

        }else{

            result[dPtr] = r[rPtr];
            rPtr++;
            
        }

        dPtr++;
    }

    return result;    
}



function binarySearchTreeOperation(){

    function findMin(node){

        if(node == null){

            return null;

        }else{

            if(node.left){

                return findMin(node.left);

            }else{

                return node;

            }

        }
    }

    function findMax(node){
        if(node == null){

            return null;

        }else{

            if(node.right){

                return findMax(node.right);

            }else{

                return node;

            }

        }
    }


    function lookup(node, value){

        if(node == null){

            return false;

        }else{

            if(node.value == value){

                return true;

            }else if(target < node.value){

                return loopup(node.left, value);

            }else{

                return loopup(node.right, value);

            }

        }

    }

    function insert(node, value){

        if(node == null){
            
            return {
                left: null,
                right: null,
                value: value,
            };

        }else{

            if(value <= node.value){
                node.left = insert(node.left, value);
            }else{
                node.right = insert(node.right, value);
            }

            return node;
        }

    }

    treeNode * Delete(treeNode *node, int data)
    {
            treeNode *temp;
            if(node==NULL)
            {
                    printf("Element Not Found");
            }
            else if(data < node->data)
            {
                    node->left = Delete(node->left, data);
            }
            else if(data > node->data)
            {
                    node->right = Delete(node->right, data);
            }
            else
            {
                    /* Now We can delete this node and replace with either minimum element 
                       in the right sub tree or maximum element in the left subtree */
                    if(node->right && node->left)
                    {
                            /* Here we will replace with minimum element in the right sub tree */
                            temp = FindMin(node->right);
                            node -> data = temp->data; 
                            /* As we replaced it with some other node, we have to delete that node */
                            node -> right = Delete(node->right,temp->data);
                    }
                    else
                    {
                            /* If there is only one or zero children then we can directly 
                               remove it from the tree and connect its parent to its child */
                            temp = node;
                            if(node->left == NULL)
                                    node = node->right;
                            else if(node->right == NULL)
                                    node = node->left;
                            free(temp); /* temp is longer required */ 
                    }
            }
            return node;

    }

    function postOrder(node){ // depth first search
        if(node == null){
            return;
        }
        postOrder(node.left);
        postOrder(node.right);
        console.log(node.value);    
    }

    function inOrder(node){ // depth first search
        if(node == null){
            return;
        }
        inOrder(node.left);
        console.log(node.value);
        inOrder(node.right);
    }

    function preOrder(){ // depth first search
        if(node == null){
            return;
        }
        console.log(node.value);
        preOrder(node.left);
        preOrder(node.right);
    }


    function levelOrder(root){ // breadth first search

        var q = [];

        var temp = root;

        while(temp){

            console.log(temp.value);

            if(temp.left){
                q.push(temp.left);
            }

            if(temp.right){
                q.push(temp.right);
            }

            temp = q.shift();
        }

    }


    var root = null;

    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 0);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 6);

    console.log(root);

    console.log(levelOrder(root).join(' '));

}






function adjacencyList(){

    function createGraph(){

        var adj = [];

        return {

            addEdge: function(v, w){
                adj[v] = adj[v] || [];
                adj[v].push(w);
            },

            bfs: function(s){

                var visited = [];
                var queue = [];
                var output = [];

                visited[s] = 1;
                queue.push(s);

                while(queue.length){

                    s = queue.shift();

                    output.push(s);

                    for(var i=0, length=adj[s].length; i<length; i++){

                        var w = adj[s][i];

                        if(!visited[w]){
                            visited[w] = 1;
                            queue.push(w);
                        }
                    }

                }

                return output;
            }

        };

    }


    var graph = createGraph();

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    console.log(graph.bfs(2));


}



function DFS(){


    function createGraph(){

        var adj = [];

        return {

            addEdge: function(v, w){

                adj[v] = adj[v] || [];
                adj[v].push(w);

            },

            dfsRecursion: function(v, visited){
                visited[v] = 1;

                console.log(v);

                for(var i=0, length=adj[v].length; i<length; i++){

                    var w = adj[v][i];

                    if(!visited[w]){
                        dfsUntil(w, visited);
                    }
                }
            },

            dfs: function(v){

                var visited = [];

                dfsUntil(v, visited);
            },

            dfsRecursionTransformToIteration: function(s){
                var stack = [];

                var visited = [];

                stack.push(s);

                while(stack.length){

                    s = stack.pop();

                    console.log(s);
                    visited[s] = 1;

                    for(var i=0; i<adj[s].length; i++){

                        var v = adj[s][i];

                        if(!visited[v]){
                            stack.push(v);
                        }

                    }
                }
            },

            iterativeDfs1: function(s){

                // bfs style dfs, from topcoder forum
                // slight different from the standard dfs
                // topcoder forum http://apps.topcoder.com/forums/;jsessionid=6957984F07F91D03E0B187E942D2ED79?module=Thread&threadID=699619&start=0&mc=5#1667411
                // described from http://stackoverflow.com/questions/8748229/implementation-of-bfs-dfs-and-dijkstra

                var visited = [];
                var stack = [];
                var output = [];

                stack.push(s);
                visited[s] = 1;

                while(stack.length){

                    var top = stack.pop();

                    output.push(top);

                    for(var i=0, length=adj[top].length; i<length; i++){

                        var w = adj[top][i];

                        if(!visited[w]){
                            stack.push(w);
                            visited[w] = 1;
                        }
                    }

                }

                return output;
            },

            iterativeDfs2: function(s){

                // this is the standard dfs

                var visited = [];
                var stack = [];
                var output = [];

                stack.push(s);

                while(stack.length){

                    var top = stack.pop();

                    if(!visited[top]){

                        output.push(top);

                        visited[top] = 1;

                        for(var length=adj[top].length, i=length-1; i>=0; i--){

                            var w = adj[top][i];

                            stack.push(w);
                        }

                    }


                }

                return output;
            }

        };

    }



    var g = createGraph();

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 6);
    g.addEdge(1, 0);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 5);
    g.addEdge(2, 7);
    g.addEdge(3, 0);
    g.addEdge(3, 5);
    g.addEdge(4, 1);
    g.addEdge(4, 6);
    g.addEdge(5, 1);
    g.addEdge(5, 2);
    g.addEdge(5, 3);
    g.addEdge(6, 0);
    g.addEdge(6, 4);
    g.addEdge(7, 2);


    console.log(g.iterativeDfs2(0));

}




function tailRecursionElimination(){

    void foo(Node* node)
    {
        if(node == NULL)
           return;
        // Do something with node...
        foo(node->left);
        foo(node->right);
    }

    void foo(Node* node)
    {
        while(node != NULL)
        {
            // Do something with node...
            foo(node->left);
            node = node->right;
         }
    }


    void foo(Node* node)
    {
        if(node == NULL)
           return;

        // Do something with node...

        stack.push(node->right);
        stack.push(node->left);

        while(!stack.empty()) {
             node1 = stack.pop();
             if(node1 == NULL)
                continue;
             // Do something with node1...
             stack.push(node1->right);             
             stack.push(node1->left);
        }

    }

}

// power set
// using recursion
#include <iostream.h>
char buf[3]={'a','b','c'}, ans[4];
int total_len=3;
void Powerset(int i, int j)
{
    if (j==total_len) {
        ans[i]=0;
        cout<<'{'<<ans<<'}'<<endl;
    }
    else {
        Powerset(i,j+1);
        ans[i]=buf[j];
        Powerset(i+1,j+1);
    }
}
void main()
{
    Powerset(0,0);
}