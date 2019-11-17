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
     * @deprecated: 使用JNative调用dll方法 
     * @author  
     * @date 2014-3-3 
     */  
    @Test  
    public void loadFile() {  
        try {  
            JNative jn = new JNative("Termb.dll", "CVR_InitComm");  
            // 设置此函数的返回值  
            jn.setRetVal(Type.INT);  
            jn.setParameter(0, Type.INT, "1001");  
            // 执行  
            jn.invoke();  
            // 返回值  
            int retVal = Integer.parseInt(jn.getRetVal());  
            // 打印函数返回值  
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