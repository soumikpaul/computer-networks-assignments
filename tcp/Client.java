 import java.io.*;
import java.net.*;
public class Client {

            public static void main(String[] args) throws Exception
            {
                                    Socket s=new Socket("127.0.0.1",7777);
                                    if(s.isConnected())
                                    {
                                                System.out.println("Connected to server");
                                    }
                                    FileOutputStream fout= new FileOutputStream("received2.pdf");
                                    DataInputStream din=new DataInputStream(s.getInputStream());
                                    int r;
                                    while((r=din.read())!=-1)
                                    {
                                                fout.write((char)r);
                                    }
                                    s.close();
            }

}
