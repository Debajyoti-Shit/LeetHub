class Solution {
    public boolean isValid(String expression) {
        Stack<Character> st= new Stack<Character>();

        for(int i=0;i<expression.length();i++){
            if(expression.charAt(i)=='(' || expression.charAt(i)=='{' || expression.charAt(i)=='['){
                st.push(expression.charAt(i));
            }
            else if(st.isEmpty()){
                return false;
            }
            else if(expression.charAt(i)==')'){
               if( st.peek()=='('){
                   st.pop();
               }else{
                   return false;
               }
            }else  if(expression.charAt(i)=='}'){
               if( st.peek()=='{'){
                   st.pop();
               }
               else{
                   return false;
               }
            }else  if(expression.charAt(i)==']'){
               if( st.peek()=='['){
                   st.pop();
               } else{
                   return false;
               }
            }
            
        }
        return st.isEmpty();

    }
}