public class Max{
    public static int[] list={5,1,2,3,7,14,6};
    public static void main(String[] args){
        int max=-1;
        for(int i=0;i<list.length;i++){
            if(list[i]>max){
                max=list[i];
            }
        }
        System.out.println(max);
    }
}
