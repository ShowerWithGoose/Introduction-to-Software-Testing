from dotenv import load_dotenv
load_dotenv()

# Run the whole pipeline
from util.config import PROJECT
import generate_error_message, generate_file_line_map, generate_ground_truth, fault_location, generate_embedding, evaluation

# The complete pipeline requires the use of services from multiple AI providers, including openai, Claude, and deepseek, so different 
# base URLs and API keys may need to be replaced at different steps. You can also use integrated AI services such as Amazon Bedrock, etc.
if __name__ == "__main__":
    if PROJECT.startswith("data_structures") or PROJECT.startswith("test_ds"):
        generate_error_message.generate_ds()
        generate_embedding.main()  # generate embedding for data structures
        generate_ground_truth.main()
        fault_location.main()  # note that different models may need different BASE_URL and API_KEY
        evaluation.generate_vote_results()
        evaluation.evaluate()
    elif PROJECT.startswith("compiler_technology"):
        generate_error_message.generate_compile()
        generate_file_line_map.main()  # generate file line map for compiler technology
        generate_ground_truth.main()
        fault_location.main()  # note that different models may need different BASE_URL and API_KEY
        evaluation.generate_vote_results()
        evaluation.evaluate()
