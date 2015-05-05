object Form1: TForm1
  Left = 183
  Top = 275
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 376
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 40
    Top = 64
    Width = 737
    Height = 49
    ColCount = 10
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 1
  end
  object StringGrid2: TStringGrid
    Left = 40
    Top = 144
    Width = 737
    Height = 49
    ColCount = 10
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 2
  end
end
