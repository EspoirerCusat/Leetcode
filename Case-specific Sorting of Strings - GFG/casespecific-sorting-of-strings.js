//{ Driver Code Starts
//Initial Template for javascript

//Initial Template for javascript
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let string = readLine();
        
        let obj = new Solution();
        let ans = obj.caseSort(string, n);
        
        console.log(ans);
    }
}
// } Driver Code Ends


//User function Template for javascript

class Solution {
    caseSort(str, n) {
       let s = [];
       let t = [];
       for(let i=0; i<n; i++){
           if(str[i] == str[i].toUpperCase()){
               s.push(str[i]);
           }else{
               t.push(str[i]);
           }
       }
       s.sort();
       t.sort();
       let idx,jdx;
       idx = jdx = 0;
       let ans = "";
       for(let i=0; i<n; i++){
           if(str[i] == str[i].toUpperCase()){
               ans += s[idx];
               idx++;
           }else{
               ans += t[jdx];
               jdx++;
           }
       }
       return ans;
    }
}

















