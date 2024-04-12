// Definindo uma classe para representar um usuário
class User {
    constructor(id, username) {
      this.id = id;
      this.username = username;
    }
  
    // Método para buscar informações do usuário de forma assíncrona
    async fetchUserInfo() {
      return new Promise((resolve, reject) => {
        // Simulando uma requisição assíncrona, por exemplo, a uma API
        setTimeout(() => {
          const userInfo = {
            id: this.id,
            username: this.username,
            email: `${this.username}@example.com`,
            joinedAt: new Date()
          };
          resolve(userInfo);
        }, 1000); // Tempo simulado de resposta: 1 segundo
      });
    }
  }
  
  // Função para buscar informações de vários usuários
  async function fetchUsersInfo(userIds) {
    const usersInfo = [];
  
    // Iterando pelos IDs dos usuários
    for (const userId of userIds) {
      // Criando instância de usuário com ID e nome de usuário
      const user = new User(userId, `user${userId}`);
      
      try {
        // Buscando informações do usuário e aguardando pela resposta assíncrona
        const userInfo = await user.fetchUserInfo();
        usersInfo.push(userInfo);
      } catch (error) {
        console.error(`Erro ao buscar informações do usuário ${userId}:`, error);
      }
    }
  
    return usersInfo;
  }
  
  // IDs dos usuários a serem buscados
  const userIds = [1, 2, 3];
  
  // Chamada da função para buscar informações dos usuários
  fetchUsersInfo(userIds)
    .then(usersInfo => {
      console.log("Informações dos usuários:", usersInfo);
    })
    .catch(error => {
      console.error("Erro ao buscar informações dos usuários:", error);
    });
 
