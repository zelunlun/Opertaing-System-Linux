/**
 * Creating a Java thread pool.
 *
 * Figure 4.15
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */

import java.util.concurrent.*;

class Task implements Runnable
{
    public void run() {
        System.out.println(Thread.currentThread().getName());//可以看出是第幾號Thread
	System.out.println("你好");
    }
}

public class ThreadPoolExample
{
    public static void main(String[] args) {
        int numTasks = Integer.parseInt(args[0].trim()); //將Command後的參數前後空格去除，並轉成整數
        
        ExecutorService pool = Executors.newCachedThreadPool(); //建立一個threadPool
        
        for (int i = 0; i < numTasks; i++)
            pool.execute(new Task());				//thread建立,並執行任務
	    //這裡不太懂, 什麼意思是生完一個thread可能沒跑完, 可能跑完了
            // The following invovles using a lambda function
            // pool.execute( () -> {System.out.println(Thread.currentThread().getName());});
            
        pool.shutdown();
    }
}
// 這個東西的好處是我們不需要去考慮Thread的數量
// 我們只需要專注於task就好
