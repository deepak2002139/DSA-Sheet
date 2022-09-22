class Solution {
    public String reverseWords(String s) {
        Stack<String> stack = new Stack<>();
        StringBuilder builder = new StringBuilder("");
        
        for (int i=s.length()-1; i>=0; i--) {
            char c = s.charAt(i);
            
            if (c == ' ') {
                stack.push(builder.toString());
                builder = new StringBuilder("");
            }
            else {
                builder.append(c);
            }
        }
        
        stack.push(builder.toString());
        
        builder = new StringBuilder();
        builder.append(stack.pop());
        
        while (stack.size() > 0) {
            builder.append(" ");
            builder.append(stack.pop());                
        }
        
        return builder.toString();
    }
}