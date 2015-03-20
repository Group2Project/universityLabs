import javax.swing.event.*;
import javax.swing.*;
import java.io.File;
import java.awt.*;
import java.util.*;




public class TestList implements ListSelectionListener {
	
	JList<File> jlst;
	File[] files;
	DefaultListModel<File> listModel;
	ArrayList<String> dir = new ArrayList<String>();
	JLabel jlbl,jlbl2;

	
	TestList()
	{
		
		//-----��������� �����-------------------------------//
		JFrame jfrm = new JFrame("G2P");                     //
		jfrm.setSize(600, 600);                              //
		jfrm.setVisible(true);                               //
		jfrm.setLayout(null);                                //
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //
		//---------------------------------------------------//
		
		//-----Test-------------------------------------//
		jlbl2 = new JLabel();							//
		jfrm.add(jlbl2);								//
		jlbl2.setBounds(300, 100, 300, 20);             //
		jlbl = new JLabel();							//
		jfrm.add(jlbl);									//
		jlbl.setBounds(300, 0, 300, 20);	            //						    
		//----------------------------------------------//
		
		//-----�������� ������� � ��������� �������� ���������--------//
		files = File.listRoots();                                     //
		//------------------------------------------------------------//
		
		//-----�������� ������ ������ � ���������� ��� ���������� �� ������� files-----//
		listModel = new DefaultListModel<File>();      								   //
		for(int i=0;i<files.length;i++)												   //
			listModel.addElement(files[i]);											   //
		//-----------------------------------------------------------------------------//
		
		//-----�������� � ��������� ������--------------------------//
		jlst = new JList<File>(listModel);                          //                          
		jlst.setSelectionMode(ListSelectionModel.SINGLE_SELECTION); //
		jlst.addListSelectionListener(this);                        //                                            
		//----------------------------------------------------------//
		
		//-----�������� ������ ��������� ��� ������--------------------------------------//
		JScrollPane jscrlp = new JScrollPane(jlst);                                      //
		jscrlp.setPreferredSize(new Dimension(50,50));                                   //
		jscrlp.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);        //
		jscrlp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED); //
		jscrlp.setBounds(0, 0, 200, 400);                                                //
		jfrm.add(jscrlp);                                                                //
		//-------------------------------------------------------------------------------//
		
		
	}	
		public void valueChanged(ListSelectionEvent le)
		{
			jlbl2.setText("");
			int indx = jlst.getSelectedIndex();
			dir.clear();
			jlbl.setText("��� ������" + indx);
			try
			{	
				dir.add(files[indx].getAbsolutePath());
				File a = new File(dir.get(0));
				files = a.listFiles();
				for(int i=0;i<files.length;i++)												   
					listModel.removeAllElements();	
				for(int i=0;i<files.length;i++)												   
					listModel.addElement(files[i]);	
				
			}
			catch(ArrayIndexOutOfBoundsException ex)
			{
				jlbl2.setText("����� �� ������� �������");
			}
			catch(NullPointerException ex)
			{
				jlbl2.setText("����� �����-��");
			}
		}
		
	public static void main(String[] args)
	{
		SwingUtilities.invokeLater(new Runnable() {
			public void run()
			{
				new TestList();
			}
		});
	}
	
	
}




