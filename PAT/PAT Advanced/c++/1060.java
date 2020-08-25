import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

// PAT Advanced 1060 Are They Equal

//第三个检查点无法通过

public class Main{
    static int N;
    static BigDecimal tailA,tailB;
    public static void main(String[] args){
        BigDecimal A,B;
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        A = in.nextBigDecimal();
        B = in.nextBigDecimal();
        //转换大实数为自定义的规格化浮点数类
        NormalizedFP nA = Normalizing(A);
        NormalizedFP nB = Normalizing(B);
        if(Compare(nA,nB))
            System.out.println("YES "+tailA+"*10^"+nA.exp);
        else
            System.out.println("NO "+tailA+"*10^"+nA.exp +" "+tailB+"*10^"+nB.exp);
    }
    static NormalizedFP Normalizing(BigDecimal target){
        // 题目给定输入浮点数非负
        NormalizedFP result = new NormalizedFP();
        result.exp = 0;
        result.mantissa = target;
        //等于0直接返回
        if(result.mantissa.compareTo(BigDecimal.valueOf(0)) == 0)
            return result;
        //尾数大于1时向下
        while (result.mantissa.compareTo(BigDecimal.valueOf(1)) > 0){
            result.mantissa = result.mantissa.divide(BigDecimal.valueOf(10));
            result.exp++;
        }
        //尾数小于0.1时向上,保证尾数第一位小数大于0（我之前没考虑到）
        while (result.mantissa.compareTo(BigDecimal.valueOf(0.1)) < 0){
            result.mantissa = result.mantissa.multiply(BigDecimal.valueOf(10));
            result.exp--;
        }
        return result;
    }
    static boolean Compare(NormalizedFP A,NormalizedFP B){
        if(A.exp != B.exp)
            return false;
        //运用setScale方法设定尾数精度，并便于打印输出，floor方法直接截断舍掉的尾数（题设）
        tailA = A.mantissa.setScale(N,RoundingMode.FLOOR);
        tailB = B.mantissa.setScale(N,RoundingMode.FLOOR);
        if(tailA.compareTo(tailB) == 0)
            return true;
        else
            return false;
    }
}
class NormalizedFP{
    int exp;
    BigDecimal mantissa;
}
