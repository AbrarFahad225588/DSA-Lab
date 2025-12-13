# from openai import OpenAI

# client = OpenAI(
#   base_url="https://openrouter.ai/api/v1",
#   api_key="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",
# )

# completion = client.chat.completions.create(
#   extra_headers={
#     "HTTP-Referer": "<YOUR_SITE_URL>", # Optional. Site URL for rankings on openrouter.ai.
#     "X-Title": "<YOUR_SITE_NAME>", # Optional. Site title for rankings on openrouter.ai.
#   },
#   model="openai/gpt-4o",
#   messages=[
#     {
#       "role": "user",
#       "content": "What is the meaning of life"
#     }
#   ]
# )
# txt=completion.choices[0].message.content
# print(txt)
# with open('fstring_file.txt', 'w') as file:
#     file.write(txt)
    
# from elevenlabs.client import ElevenLabs
# from elevenlabs import play

# client = ElevenLabs(
#     api_key="sk_0a78d57a3c06fc8b9db3087d453b7e65f1c47f463df476e0"
# )

# audio = client.text_to_speech.convert(
#     text="The first move is what sets everything in motion.",
#     voice_id="JBFqnCBsd6RMkjVDRZzb",
#     model_id="eleven_multilingual_v2",
#     output_format="mp3_44100_128",
# )

# play(audio)
# from elevenlabs import ElevenLabs, play

# client = ElevenLabs(api_key="sk_0a78d57a3c06fc8b9db3087d453b7e65f1c47f463df476e0")

# # Generate audio
# audio = client.text_to_speech.convert(
#     text="The first move is what sets everything in motion.",
#     voice_id="JBFqnCBsd6RMkjVDRZzb",
#     model_id="eleven_multilingual_v2",
#     output_format="mp3_44100_128"
# )

# # The 'convert' method returns bytes, so just pass it to play()
# play(audio)
# from elevenlabs import play, generate

# audio = generate(
#     text="Hello! This is a test voice from ElevenLabs.",
#     voice="Rachel",
#     model="eleven_multilingual_v2"
# )

# play(audio)
import openai
import os

# Set your OpenAI API key from an environment variable for security
# Replace 'YOUR_OPENAI_API_KEY' with your actual API key for direct assignment
# For production, always use environment variables
openai.api_key = os.getenv("sk-1234ijkl1234ijkl1234ijkl1234ijkl1234ijkl") 

if openai.api_key is None:
    print("Error: OPENAI_API_KEY environment variable not set.")
    print("Please set the OPENAI_API_KEY environment variable or assign your key directly.")
else:
    try:
        # Define the prompt for text generation
        prompt_text = "Write a short, creative story about a robot who discovers a love for painting."

        # Make an API call to create a chat completion
        response = openai.chat.completions.create(
            model="gpt-4o",  # Specify the desired model (e.g., "gpt-4o", "gpt-3.5-turbo")
            messages=[
                {"role": "system", "content": "You are a helpful assistant."},
                {"role": "user", "content": prompt_text}
            ],
            max_tokens=150,  # Limit the length of the generated response
            temperature=0.7  # Control the randomness of the output (0.0 to 1.0)
        )

        # Extract and print the generated text
        generated_text = response.choices[0].message.content
        print("Generated Story:")
        print(generated_text)

    except openai.APIError as e:
        print(f"OpenAI API Error: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")