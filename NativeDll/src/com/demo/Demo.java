package com.demo;

import org.xvolks.jnative.JNative;
import org.xvolks.jnative.Type;

public class Demo {

	public static void main(String[] args) {
		try {
			JNative n = new JNative("Termb.dll", "CVR_InitComm");
			n.setRetVal(Type.INT); // ָ�����ز���������
			n.setParameter(0, 1001);
			n.invoke(); // ���÷���
			System.out.println(Integer.parseInt(n.getRetVal()));
//			GetPeopleName();
			
			n = new JNative("Termb.dll", "CVR_Authenticate"); 
            n.setRetVal(Type.INT); // ָ�����ز���������                              
            n.invoke(); // ���÷���
            System.out.println(Integer.parseInt(n.getRetVal()));
			
            n = new JNative("Termb.dll", "CVR_Read_Content"); 
            n.setRetVal(Type.INT); // ָ�����ز���������
            n.setParameter(0, 4);                   
            n.invoke(); // ���÷���
            System.out.println(Integer.parseInt(n.getRetVal()));
            
		} catch (Exception e) {
			e.printStackTrace();
		} 

	}
}
