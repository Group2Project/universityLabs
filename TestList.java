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
		
		//-----Настройка формы-------------------------------//
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
		
		//-----Создание массива с названием корневых каталогов--------//
		files = File.listRoots();                                     //
		//------------------------------------------------------------//
		
		//-----Создание модели списка и заполнение его элементами из массива files-----//
		listModel = new DefaultListModel<File>();      								   //
		for(int i=0;i<files.length;i++)												   //
			listModel.addElement(files[i]);											   //
		//-----------------------------------------------------------------------------//
		
		//-----Создание и настройка списка--------------------------//
		jlst = new JList<File>(listModel);                          //                          
		jlst.setSelectionMode(ListSelectionModel.SINGLE_SELECTION); //
		jlst.addListSelectionListener(this);                        //                                            
		//----------------------------------------------------------//
		
		//-----Создание панели прокрутки для списка--------------------------------------//
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
			jlbl.setText("Был выбран" + indx);
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
				jlbl2.setText("Выход за границы массива");
			}
			catch(NullPointerException ex)
			{
				jlbl2.setText("Херня какая-то");
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




