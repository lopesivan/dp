package Command;

# Classe base para as operações (comandos)
sub new {
  my $class = shift;
  my $self = {};
  bless $self, $class;
  return $self;
}

sub execute {
  die "Método 'execute' não implementado";
}

package AddCommand;

# Classe concreta para a operação "Adicionar"
use base 'Command';

sub new {
  my $class = shift;
  my $self = $class->SUPER::new();
  $self->{x} = shift;
  $self->{y} = shift;
  return $self;
}

sub execute {
  my $self = shift;
  print $self->{x} + $self->{y} . "\n";
}

package SubtractCommand;

# Classe concreta para a operação "Subtrair"
use base 'Command';

sub new {
  my $class = shift;
  my $self = $class->SUPER::new();
  $self->{x} = shift;
  $self->{y} = shift;
  return $self;
}

sub execute {
  my $self = shift;
  print $self->{x} - $self->{y} . "\n";
}

package Calculator;

# Classe que armazena e executa um comando
sub new {
  my $class = shift;
  my $self = {};
  $self->{command} = undef;
  bless $self, $class;
  return $self;
}

sub set_command {
  my $self = shift;
  $self->{command} = shift;
}

sub execute_command {
  my $self = shift;
  $self->{command}->execute();
}

sub main {
  my $calculator = Calculator->new();

  # Define e executa o comando "Adicionar"
  $calculator->set_command(AddCommand->new(10, 5));
  $calculator->execute_command();  # Imprime 15

  # Define e executa o comando "Subtrair"
  $calculator->set_command(SubtractCommand->new(10, 5));
  $calculator->execute_command();  # Imprime 5
}

main();
