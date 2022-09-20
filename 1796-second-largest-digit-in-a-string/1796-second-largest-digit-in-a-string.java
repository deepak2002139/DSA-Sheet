class Solution {
    public int secondHighest(String s) 
    {
        PriorityQueue <Integer> pq= new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0; i<s.length(); i++) 
            if(Character.isDigit(s.charAt(i))) 
                if(!pq.contains(s.charAt(i)-'0')) pq.add(s.charAt(i)-'0');
        pq.poll();
        if(pq.isEmpty()) 
            return -1;
        return pq.poll();
        
    }
}