import javax.swing.event.*;
import javax.swing.*;
import java.io.*;
import java.awt.*;

class ChangeThread implements Runnable
{
	private File[] a;
	private DefaultListModel b;
	ChangeThread(File[] cat,DefaultListModel list2)
	{
		a = cat;
		b = list2;
		
	}
	public void run()
	{
		for(int i=0;i<a.length;i++)
			b.addElement(i);
		 
	}
	DefaultListModel change()
	{
		return b;	
	}
}

class DeleteThread implements Runnable
{
	private File[] a;
	private DefaultListModel b;
	DeleteThread(File[] cat,DefaultListModel list2)
	{
		a = cat;
		b = list2;
		
	}
	public void run()
	{
		b.removeAllElements();
		 
	}
	
	DefaultListModel change()
	{
		return b;
	}
}

public class TestList implements ListSelectionListener {
	
	public JList jlst,jlst2;
	public File ctlg,sel_cat;
	public File[] files,sel_catalog;
	public DefaultListModel listModel,listModel2;
	JFrame jfrm;
	
	TestList()
	{
		
		jfrm = new JFrame();
		jfrm.setSize(600, 600);
		jfrm.setVisible(true);
		jfrm.setLayout(null);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		files = File.listRoots();
		
		listModel = new DefaultListModel();
		for(int i=0;i<files.length;i++)
			listModel.addElement(files[i]);
		
		
		jlst = new JList(listModel);
		jlst.setBounds(0, 0, 200, 400);
		jlst.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		jlst.addListSelectionListener(this);
		jfrm.add(jlst);
		
		JScrollPane jscrlp = new JScrollPane();
		jscrlp.setPreferredSize(new Dimension(120,90));
		
		
		
	}	
		public void valueChanged(ListSelectionEvent le)
		{
			
			int select = jlst.getSelectedIndex(); //Получение индекса выбранного элемента
			String dir = new String(files[select].getAbsolutePath()); //Получение адреса выбранного элемента
			sel_cat = new File(dir);
			sel_catalog = sel_cat.listFiles();
			
		
			
			ChangeThread ct = new ChangeThread(sel_catalog,listModel);
			Thread newct = new Thread(ct);
			newct.start();
			listModel=ct.change();
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




