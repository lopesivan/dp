{ Classe base para as operações (comandos) }
type
  TCommand = class
  public
    procedure Execute; virtual; abstract;
  end;

  { Classe concreta para a operação "Adicionar" }
  TAddCommand = class(TCommand)
  private
    FX: Integer;
    FY: Integer;
  public
    constructor Create(X, Y: Integer);
    procedure Execute; override;
  end;

  { Classe concreta para a operação "Subtrair" }
  TSubtractCommand = class(TCommand)
  private
    FX: Integer;
    FY: Integer;
  public
    constructor Create(X, Y: Integer);
    procedure Execute; override;
  end;

  { Classe que armazena e executa um comando }
  TCalculator = class
  private
    FCommand: TCommand;
  public
    procedure SetCommand(Command: TCommand);
    procedure ExecuteCommand;
  end;

{ Implementação das classes }

constructor TAddCommand.Create(X, Y: Integer);
begin
  inherited Create;
  FX := X;
  FY := Y;
end;

procedure TAddCommand.Execute;
begin
  WriteLn(FX + FY);
end;

constructor TSubtractCommand.Create(X, Y: Integer);
begin
  inherited Create;
  FX := X;
  FY := Y;
end;

procedure TSubtractCommand.Execute;
begin
  WriteLn(FX - FY);
end;

procedure TCalculator.SetCommand(Command: TCommand);
begin
  FCommand := Command;
end;

procedure TCalculator.ExecuteCommand;
begin
  FCommand.Execute;
end;

{ Programa principal }

var
  Calculator: TCalculator;

begin
  Calculator := TCalculator.Create;

  { Define e executa o comando "Adicionar" }
  Calculator.SetCommand(TAddCommand.Create(10, 5));
  Calculator.ExecuteCommand;  { Imprime 15 }

  { Define e executa o comando "Subtrair" }
  Calculator.SetCommand(TSubtractCommand.Create(10, 5));
  Calculator.ExecuteCommand;  { Imprime 5 }
end.
