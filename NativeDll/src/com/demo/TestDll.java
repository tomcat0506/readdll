package com.demo;
import org.junit.Before;  
import org.junit.Test;  
import org.xvolks.jnative.JNative;  
import org.xvolks.jnative.Type;  
import org.xvolks.jnative.exceptions.NativeException;  
  
public class TestDll {  
//  
////    @Before  
//    public void setUp() throws Exception {  
//  
//        try {  
//  
//            String userDir = System.getProperty("user.dir");  
//            System.out.println(userDir);
//            
////            System.load(userDir.concat("/sdtapi.dll"));  
//            System.load(userDir.concat("/Termb.dll"));  
////            System.load(userDir.concat("/WltRS.dll"));  
//        } catch (Exception e) {  
//            e.printStackTrace();  
//        }  
//    }  
//  
    /** 
     * @Title: test 
     * @deprecated: ʹ��JNative����dll���� 
     * @author  
     * @date 2014-3-3 
     */  
    @Test  
    public void loadFile() {  
        try {  
            JNative jn = new JNative("Termb.dll", "CVR_InitComm");  
            // ���ô˺����ķ���ֵ  
            jn.setRetVal(Type.INT);  
            jn.setParameter(0, Type.INT, "1001");  
            // ִ��  
            jn.invoke();  
            // ����ֵ  
            int retVal = Integer.parseInt(jn.getRetVal());  
            // ��ӡ��������ֵ  
            System.out.println(retVal);  
  
        } catch (NativeException e) {  
            e.printStackTrace();  
        } catch (IllegalAccessException e) {  
            e.printStackTrace();  
        } catch (Exception e) {  
            e.printStackTrace();  
        }  
    }  
}  