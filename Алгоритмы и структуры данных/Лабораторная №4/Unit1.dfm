object Form1: TForm1
  Left = 192
  Top = 124
  Width = 870
  Height = 640
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 64
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object CSpinEdit1: TCSpinEdit
    Left = 40
    Top = 32
    Width = 129
    Height = 22
    TabOrder = 1
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 128
    Width = 737
    Height = 65
    ColCount = 10
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 2
  end
end
